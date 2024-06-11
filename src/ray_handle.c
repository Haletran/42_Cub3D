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

int  out_map(t_mlx *mlx, double y, double x)
{
	if (y < 0 || y > mlx->map->height * 32 || x < 0 || x > mlx->map->width * 32)
	{
		mlx->ray->dist = 0;
		mlx->ray->hit = 1;
		return (0);
	}
	return (1);
}


void	get_horizontal_hit(t_mlx *mlx)
{
	double	h_x;
	double	h_y;
	int count = 0;


	h_y = (mlx->player->y / 32) * 32;
	h_x = mlx->player->x + (h_y - mlx->player->y) / tan(mlx->ray->ray_angle);
	if (mlx->map->map[((int)h_y / 32)][((int)h_x / 32)] == '1')
	{
		mlx->ray->h_dist = pythagoras(mlx, h_x, h_y);
		return ;
	}
	init_step(mlx, 'h');
	while (!mlx->ray->hit && count < 20)
	{
		h_x += mlx->ray->step_x;
		h_y += mlx->ray->step_y;
		if (out_map(mlx, h_y, h_x) && mlx->map->map[((int)h_y / 32)][((int)h_x / 32)] == '1')
		{
			mlx->ray->h_dist = pythagoras(mlx, h_x, h_y);
			mlx->ray->hit = 1;
		}
	}
	mlx->ray->x = h_x;
	mlx->ray->y = h_y;
	mlx->ray->hit = 0;
}

void	get_vertical_hit(t_mlx *mlx)
{
	double	v_x;
	double	v_y;
	int count = 0;

	v_x = (mlx->player->x / 32) * 32;
	v_y = mlx->player->y + (v_x - mlx->player->x) / tan(mlx->ray->ray_angle);
	if (mlx->map->map[((int)v_y / 32)][((int)v_x / 32)] == '1')
	{
		mlx->ray->v_dist = pythagoras(mlx, v_x, v_y);
		return ;
	}
	init_step(mlx, 'v');
	while (!mlx->ray->hit && count < 20)
	{
		v_x += mlx->ray->step_x;
		v_y += mlx->ray->step_y;
		if (out_map(mlx, v_y, v_x) && mlx->map->map[((int)v_y / 32)][((int)v_x / 32)] == '1')
		{
			mlx->ray->v_dist = pythagoras(mlx, v_x, v_y);
			mlx->ray->hit = 1;
		}
	}
	mlx->ray->step_x = v_x;
	mlx->ray->step_y = v_y;
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
		i++;
	}
	if (mlx->map->print == 0)
		draw_map(mlx);
}
