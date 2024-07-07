#include "../includes/cub3d.h"

/*
horizontale
si vers le bas, y + 32 et pixel = -1
sinon step_y *= -1 et pixel = 1

verticale
si pas vers la gauche x + 32 et pixel = -1
sinon step_x *= -1 et pixel = 1
 */

/*
horizontale
si vers le bas et step_x > 0 || si pas vers le bas et step_x < 0
	step_x *= -1;

verticale
si vers la gauche et step_y < 0 || si pas vers la gauche et step_y > 0
	step_y *= -1;
 */

void	print_data(t_mlx *mlx, float x, float y, int h)
{
	if (h)
		printf("HORIZONTAL\n");
	else
		printf("VERTICAL\n");
	printf("x: %f\n", x);
	printf("y: %f\n", y);
	printf("step_x: %f\n", mlx->ray->step_x);
	printf("step_y: %f\n", mlx->ray->step_y);
	printf("pix: %d\n", mlx->ray->pix);
}

void	draw_ray(t_mlx *mlx)
{
	int		x;
	int		y;
	int		j;
	int		color;

	x = mlx->player->x;
	y = mlx->player->y;
	j = 0;
	while (j < mlx->ray->dist)
	{
		x = mlx->player->x + j * cos(mlx->ray->ray_angle);
		y = mlx->player->y + j * sin(mlx->ray->ray_angle);
		if (x < 0 || y < 0 || x > mlx->map->data_map->width * 32 || y > mlx->map->data_map->height * 32)
			break;
		color = 0x00FF00;
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, color);
		j++;
	}
}

int	check_neg_step(t_mlx *mlx, int h)
{
	if (h)
	{
		if(mlx->ray->ray_angle > (PI / 2) && mlx->ray->ray_angle < ((3 * PI) / 2))
			return (1);
	}
	else
	{
		if(mlx->ray->ray_angle > 0 && mlx->ray->ray_angle < PI)
			return (1);
	}
	return (0);
}

void	init_step(t_mlx *mlx, float *inter, char c)
{
	mlx->ray->pix = 1;
	if (c == 'h')
	{
		mlx->ray->step_x = 32 / tan(mlx->ray->ray_angle);
		mlx->ray->step_y = 32;
		if (mlx->ray->ray_angle > 0 && mlx->ray->ray_angle < PI)
		{
			*inter += 32;
			mlx->ray->pix = -1;
		}
		else
			mlx->ray->step_y *= -1;
	}
	else if (c == 'v')
	{
		mlx->ray->step_x = 32;
		mlx->ray->step_y = 32 * tan(mlx->ray->ray_angle);
		if (!(mlx->ray->ray_angle >  PI / 2 && mlx->ray->ray_angle < 3 * PI / 2))
		{
			*inter += 32;
			mlx->ray->pix = -1;
		}
		else
			mlx->ray->step_x *= -1;
	}
}

int	hit_wall(t_mlx *mlx, float x, float y)
{
	int	pos_x;
	int pos_y;

	if (x < 0 || y < 0)
		return (0);
	pos_x = (int)x / 32;
	pos_y = (int)y / 32;
	if (pos_y >= mlx->map->data_map->height || pos_x >= mlx->map->data_map->width)
		return (0);
	if (mlx->map->map[pos_y] && mlx->map->map[pos_y][pos_x])
	{
		if (mlx->map->map[pos_y][pos_x] == '1')
			return (0);
	}
	return (1);
}

float	get_horizontal_hit(t_mlx *mlx)
{
	float	h_x;
	float	h_y;

	h_y = ((int)mlx->player->y / 32) * 32;
	init_step(mlx, &h_y, 'h');
	h_x = mlx->player->x + (h_y - mlx->player->y) / tan(mlx->ray->ray_angle);
	if((check_neg_step(mlx, 1) && mlx->ray->step_x > 0) || (!check_neg_step(mlx, 1) && mlx->ray->step_x < 0))
		mlx->ray->step_x *= -1;
	while (hit_wall(mlx, h_x, h_y - mlx->ray->pix))
	{
		h_x += mlx->ray->step_x;
		h_y += mlx->ray->step_y;
	}
	mlx->ray->x = h_x;
	mlx->ray->y = h_y;
	return(pythagoras(mlx, mlx->ray->x, mlx->ray->y));
}

float	get_vertical_hit(t_mlx *mlx)
{
	float	v_x;
	float	v_y;

	v_x = ((int)mlx->player->x / 32) * 32;
	init_step(mlx, &v_x, 'v');
	v_y = mlx->player->y + (v_x - mlx->player->x) * tan(mlx->ray->ray_angle);
	if((check_neg_step(mlx, 0) && mlx->ray->step_y < 0 )|| (!check_neg_step(mlx, 0) && mlx->ray->step_y > 0))
		mlx->ray->step_y *= -1;
	while (hit_wall(mlx, v_x - mlx->ray->pix, v_y))
	{
		v_x += mlx->ray->step_x;
		v_y += mlx->ray->step_y;
	}
	mlx->ray->step_x = v_x;
	mlx->ray->step_y = v_y;
	return(pythagoras(mlx, mlx->ray->step_x, mlx->ray->step_y));
}

void	find_ray_lenght(t_mlx *mlx)
{
	float	h_dist;
	float	v_dist;

	h_dist = get_horizontal_hit(mlx);
	v_dist = get_vertical_hit(mlx);
	if (h_dist < v_dist)
	{
		mlx->ray->h_hit = 1;
		mlx->ray->dist = h_dist;
	}
	else
	{
		mlx->ray->x = mlx->ray->step_x;
		mlx->ray->y = mlx->ray->step_y;
		mlx->ray->dist = v_dist;
	}
}

void	fov_details(t_mlx *mlx)
{
	int		i;

	i = 0;
	mlx->ray->ray_angle = mlx->player->angle - (((FOV / 2) * PI) / 180);
	if (mlx->ray->ray_angle < 0)
		mlx->ray->ray_angle += 2 * PI;
	while (i <= RAYS)
	{
		mlx->ray->h_hit = 0;
		find_ray_lenght(mlx);
		//if (i % 100 == 0)
		//	draw_ray(mlx);
		draw_wall(mlx, i);
		mlx->ray->ray_angle += ((FOV * PI) / 180) / RAYS;
		if (mlx->ray->ray_angle > 2 * PI)
			mlx->ray->ray_angle -= 2 * PI;
		i++;
	}
	//if (mlx->map->print == 0)
	//	draw_map(mlx);
}