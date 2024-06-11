#include "../includes/cub3d.h"

/* recherche horizontale
if en bas, h_y + 32 et pixel = -1
else y_step => - y_step et pixel = 1;
if a gauche et x_step > 0 ou pas a gauche et x_step < 0
x_step => - x_step;*/

/*recherche verticale
if a droite v_x + 32 et pixel = -1
else x_step => - x_step et pixel = 1;
if en bas et y_step < 0 ou pas en bas et y_step > 0
y_step => - Y_step; */

int	dir_search(t_mlx *mlx, double *y, int h)
{
	if (h)
	{
		if (mlx->ray->ray_angle > 0 && mlx->ray->ray_angle < PI)
		{
			*y += 32;
			return (-1);
		}
		mlx->ray->step_y *= -1;
	}
	else
	{
		if (mlx->ray->ray_angle < (3 * PI) / 2 && mlx->ray->ray_angle > (PI / 2))
		{
			*y += 32;
			return (-1);
		}
		mlx->ray->step_x *= -1;
	}
	return (1);
}

int		out_map(t_mlx *mlx, int y, int x)
{
	if (x < 0)
		return (0);
	if (y < 0)
		return (0);
	if (x > mlx->map->width)
		return (0);
	if (y > mlx->map->height)
		return (0);
	return (1);
}

int	angle_search(t_mlx *mlx, char c)
{
	if (c == 'h')
	{
		if (mlx->ray->ray_angle > PI / 2 && mlx->ray->ray_angle < 3 * PI / 2)
			return (1);
	}
	if (c == 'v')
	{
		if (mlx->ray->ray_angle > 0 && mlx->ray->ray_angle < PI)
			return (1);
	}
	return (0);
}

void	init_step(t_mlx *mlx, char c)
{
	if (c == 'h')
	{
		mlx->ray->step_x = 32 / tan(mlx->ray->ray_angle);
		mlx->ray->step_y = 32;
	}
	else if (c == 'v')
	{
		mlx->ray->step_x = 32;
		mlx->ray->step_y = 32 * tan(mlx->ray->ray_angle);
	}
}

void	hit_h_wall(t_mlx *mlx, double y, double x)
{
	int	pos_x;
	int	pos_y;

	pos_x = (int)x / 32;
	pos_y = (int)y / 32;
	if (out_map(mlx, pos_y, pos_x) && mlx->map->map[pos_y][pos_x] == '1')
	{
		mlx->ray->x = x;
		mlx->ray->y = y;
		mlx->ray->h_dist = pythagoras(mlx, x, y);
		mlx->ray->hit = 1;
	}
}


void	get_horizontal_hit(t_mlx *mlx)
{
	double	h_x;
	double	h_y;
	int		pix;
	int		count;

	count = 0;
	h_y = (mlx->player->y / 32) * 32;
	h_x = mlx->player->x + (h_y - mlx->player->y) / tan(mlx->ray->ray_angle);
	hit_h_wall(mlx, h_y, h_x);
	if(mlx->ray->hit)
		return;
	init_step(mlx, 'h');
	pix = dir_search(mlx, &h_y, 1);
	if ((angle_search(mlx, 'h') && mlx->ray->step_x > 0) || (!angle_search(mlx, 'h') && mlx->ray->step_x < 0) )
		mlx->ray->step_x *= -1;
	while (!mlx->ray->hit && count < 50)
	{
		h_x += mlx->ray->step_x;
		h_y += mlx->ray->step_y;
		hit_h_wall(mlx, h_y - pix, h_x);
		count++;
	}
	mlx->ray->hit = 0;
}

void	hit_v_wall(t_mlx *mlx, double y, double x)
{
	int	pos_x;
	int	pos_y;

	pos_x = (int)x / 32;
	pos_y = (int)y / 32;
	if (out_map(mlx, pos_y, pos_x) && mlx->map->map[pos_y][pos_x] == '1' )
	{
		mlx->ray->step_x = x;
		mlx->ray->step_y = y;
		mlx->ray->v_dist = pythagoras(mlx, x, y);
		mlx->ray->hit = 1;
	}
}



void	get_vertical_hit(t_mlx *mlx)
{
	double	v_x;
	double	v_y;
	int		count;
	int		pix;

	count = 0;
	v_x = (mlx->player->x / 32) * 32;
	v_y = mlx->player->y + (v_x - mlx->player->x) * tan(mlx->ray->ray_angle);
	hit_v_wall(mlx, v_y, v_x);
	if(mlx->ray->hit)
		return;
	init_step(mlx, 'v');
	pix = dir_search(mlx, &v_x, 0);
	if ((angle_search(mlx, 'y') && mlx->ray->step_y < 0) || (!angle_search(mlx, 'h') && mlx->ray->step_y > 0) )
		mlx->ray->step_y *= -1;
	while (!mlx->ray->hit && count < 50)
	{
		v_x += mlx->ray->step_x;
		v_y += mlx->ray->step_y;
		hit_v_wall(mlx, v_y, v_x - pix);
		count++;
	}
	mlx->ray->hit = 0;
}

void	find_ray_lenght(t_mlx *mlx)
{
	mlx->ray->hit = 0;
	get_horizontal_hit(mlx);
	get_vertical_hit(mlx);
	if (mlx->ray->h_dist < mlx->ray->v_dist)
		mlx->ray->dist = pythagoras(mlx, mlx->ray->x, mlx->ray->y);
	else
		mlx->ray->dist = pythagoras(mlx, mlx->ray->step_x, mlx->ray->step_y);
}

void	fov_details(t_mlx *mlx)
{
	int		i;

	i = 0;
	mlx->ray->ray_angle = mlx->player->angle - (((FOV / 2) * PI) / 180);
	while (i <= WINDOW_WIDTH)
	{
		find_ray_lenght(mlx);
		draw_wall(mlx, i);
		mlx->ray->ray_angle += ((FOV * PI) / 180) / WINDOW_WIDTH;
		printf("ray n'%d\n", i);
		i++;
	}
	if (mlx->map->print == 0)
		draw_map(mlx);
}

