/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:24:46 by bapasqui          #+#    #+#             */
/*   Updated: 2024/06/18 21:47:22 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_fov(t_mlx *mlx)
{
	int	i;

	i = 0;
	mlx->player->save = mlx->player->angle;
	mlx->player->angle -= (((FOV * PI) / 180) / RAYS) * RAYS / 2;
	while (i <= RAYS)
	{
		mlx->player->angle += (((FOV * PI) / 180) / RAYS);
		if (mlx->player->angle >= 2 * PI)
			mlx->player->angle -= 2 * PI;
		mlx->ray->ray_angle = mlx->player->angle;
		mlx->player->delta_x = cos(mlx->player->angle) * 5;
		mlx->player->delta_y = sin(mlx->player->angle) * 5;
		rotate_line(mlx, i);
		i++;
	}
	mlx->player->angle = mlx->player->save;
}

void	rotate_line(t_mlx *mlx, int r)
{
	float	i;
	double	x;
	double	y;

	i = 0;
	while (1)
	{
		x = mlx->player->x + i * cos(mlx->ray->ray_angle);
		y = mlx->player->y + i * sin(mlx->ray->ray_angle);
		if (mlx->map->map[(int)y / 32][(int)x / 32] == '1')
			break ;
		if (mlx->map->print == 0)
			mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0xFFE8FF00);
		i += 0.1;
	}
	draw_wall(mlx, x, y, r);
	if (mlx->map->print == 0)
		draw_map(mlx);
}
//  Collision
int	key_hook(int key, void *param)
{
	t_mlx	*mlx;

	mlx = param;
	if (key == 'w')
	{
		if (mlx->map->map[(int)(mlx->player->y + mlx->player->delta_y)
			/ 32][(int)(mlx->player->x + mlx->player->delta_x) / 32] != '1')
			basic_direction("w", mlx);
	}
	if (key == 's')
	{
		if (mlx->map->map[(int)(mlx->player->y + mlx->player->delta_y)
			/ 32][(int)(mlx->player->x + mlx->player->delta_x) / 32] != '1')
			basic_direction("s", mlx);
	}
	if (key == LEFT_ARROW)
		rotation_direction("left", mlx);
	if (key == RIGHT_ARROW)
		rotation_direction("right", mlx);
	if (key == 'a' && mlx->map->map[(int)(mlx->player->y - mlx->player->delta_y)
		/ 32][(int)(mlx->player->x - mlx->player->delta_x) / 32] != '1')
	{
		if (mlx->player->angle > PI / 2 && mlx->player->angle < 3 * PI / 2)
		{
			mlx->player->delta_x = cos(mlx->player->angle + PI / 2) * 5;
			mlx->player->delta_y = sin(mlx->player->angle + PI / 2) * 5;
			mlx->player->x += mlx->player->delta_x;
			mlx->player->y += mlx->player->delta_y;
		}
		else
		{
			mlx->player->delta_x = cos(mlx->player->angle + PI / 2) * 5;
			mlx->player->delta_y = sin(mlx->player->angle + PI / 2) * 5;
			mlx->player->x -= mlx->player->delta_x;
			mlx->player->y -= mlx->player->delta_y;
		}
	}
	if (key == 'd' && mlx->map->map[(int)(mlx->player->y - mlx->player->delta_y)
		/ 32][(int)(mlx->player->x - mlx->player->delta_x) / 32] != '1')
	{
		if (mlx->player->angle > PI / 2 && mlx->player->angle < 3 * PI / 2)
		{
			mlx->player->delta_x = cos(mlx->player->angle + PI / 2) * 5;
			mlx->player->delta_y = sin(mlx->player->angle + PI / 2) * 5;
			mlx->player->x -= mlx->player->delta_x;
			mlx->player->y -= mlx->player->delta_y;
		}
		else
		{
			mlx->player->delta_x = cos(mlx->player->angle + PI / 2) * 5;
			mlx->player->delta_y = sin(mlx->player->angle + PI / 2) * 5;
			mlx->player->x += mlx->player->delta_x;
			mlx->player->y += mlx->player->delta_y;
		}
	}
	if (key == 'm')
	{
		if (mlx->map->print == 0)
			mlx->map->print = 1;
		else
			mlx->map->print = 0;
	}
	//mlx_clear_window(mlx->mlx, mlx->win);
	if (mlx->map->print == 0)
		draw_map(mlx);
	rotate_fov(mlx);
	return (0);
}
