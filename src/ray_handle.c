#include "../includes/cub3d.h"

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
		mlx->ray->step_y = 32 / tan(mlx->ray->ray_angle);
	}
	if (mlx->ray->ray_angle > PI / 2 && mlx->ray->ray_angle < PI)
			mlx->ray->step_x *= -1;
		else if (mlx->ray->ray_angle > PI && mlx->ray->ray_angle < 3 * PI / 2)
		{
			mlx->ray->step_x *= -1;
			mlx->ray->step_y *= -1;
		}
		else if (mlx->ray->ray_angle > 3 * PI / 2)
			mlx->ray->step_y *= -1;
}

void	get_horizontal_hit(t_mlx *mlx)
{
	double	h_x;
	double	h_y;
	h_y = (mlx->player->y / 32) * 32;
	h_x = mlx->player->x + (h_y - mlx->player->y) / tan(mlx->ray->ray_angle);
	if (mlx->map->map[((int)h_y / 32)][((int)h_x / 32)] == '1')
	{
		mlx->ray->h_dist = pythagoras(mlx, h_x, h_y);
		return ;
	}
	init_step(mlx, 'h');
	printf("ray angle => %f\n", mlx->ray->ray_angle);
	while (!mlx->ray->hit)
	{
		h_x += mlx->ray->step_x;
		h_y += mlx->ray->step_y;
		printf("h_y => %f\nh_x => %f\n", h_y, h_x);
		if (mlx->map->map[((int)h_y / 32)][((int)h_x / 32)] == '1')
		{
			mlx->ray->h_dist = pythagoras(mlx, h_x, h_y);
			mlx->ray->hit = 1;
		}
	}
	mlx->ray->x = h_x;
	mlx->ray->y = h_y;
	// printf("h_y => %d\nh_x => %d\n", ((int)h_y / 32), ((int)h_x / 32));
	mlx->ray->hit = 0;
}

void	get_vertical_hit(t_mlx *mlx)
{
	double	v_x;
	double	v_y;

	v_x = (mlx->player->x / 32) * 32;
	v_y = mlx->player->y + (v_x - mlx->player->x) / tan(mlx->ray->ray_angle);
	if (mlx->map->map[((int)v_y / 32)][((int)v_x / 32)] == '1')
	{
		mlx->ray->v_dist = pythagoras(mlx, v_x, v_y);
		return ;
	}
	init_step(mlx, 'v');
	while (!mlx->ray->hit)
	{
		v_x += mlx->ray->step_x;
		v_y += mlx->ray->step_y;
		if (mlx->map->map[((int)v_y / 32)][((int)v_x / 32)] == '1')
		{
			mlx->ray->v_dist = pythagoras(mlx, v_x, v_y);
			mlx->ray->hit = 1;
		}
	}
	mlx->ray->step_x = v_x;
	mlx->ray->step_y = v_y;
	// printf("v_y => %d\nv_x => %d\n", ((int)v_y / 32), ((int)v_x / 32));
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

