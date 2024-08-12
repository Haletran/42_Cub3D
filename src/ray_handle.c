/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <qdeviann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 21:35:20 by bapasqui          #+#    #+#             */
/*   Updated: 2024/08/12 10:35:05 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_step(t_mlx *mlx, float *inter, char c)
{
	mlx->ray->pix = 1;
	if (c == 'h')
	{
		mlx->ray->step_x = TILL_S / tan(mlx->ray->ray_angle);
		mlx->ray->step_y = TILL_S;
		if (mlx->ray->ray_angle > 0 && mlx->ray->ray_angle < PI)
		{
			*inter += TILL_S;
			mlx->ray->pix = -1;
		}
		else
			mlx->ray->step_y *= -1;
	}
	else if (c == 'v')
	{
		mlx->ray->step_x = TILL_S;
		mlx->ray->step_y = TILL_S * tan(mlx->ray->ray_angle);
		if (!(mlx->ray->ray_angle > PI / 2 && mlx->ray->ray_angle < 3 * PI / 2))
		{
			*inter += TILL_S;
			mlx->ray->pix = -1;
		}
		else
			mlx->ray->step_x *= -1;
	}
}

int	hit_wall(t_mlx *mlx, float x, float y)
{
	int	pos_x;
	int	pos_y;

	if (x < 0 || y < 0)
		return (0);
	pos_x = (int)x / TILL_S;
	pos_y = (int)y / TILL_S;
	if (pos_y >= mlx->map->data_map->height
		|| pos_x >= mlx->map->data_map->width)
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

	h_y = ((int)mlx->player->y / TILL_S) * TILL_S;
	init_step(mlx, &h_y, 'h');
	h_x = mlx->player->x + (h_y - mlx->player->y) / tan(mlx->ray->ray_angle);
	if ((check_neg_step(mlx, 1) && mlx->ray->step_x > 0)
		|| (!check_neg_step(mlx, 1) && mlx->ray->step_x < 0))
		mlx->ray->step_x *= -1;
	while (hit_wall(mlx, h_x, h_y - mlx->ray->pix))
	{
		h_x += mlx->ray->step_x;
		h_y += mlx->ray->step_y;
	}
	mlx->ray->x = h_x;
	mlx->ray->y = h_y;
	return (pythagoras(mlx, mlx->ray->x, mlx->ray->y));
}

float	get_vertical_hit(t_mlx *mlx)
{
	float	v_x;
	float	v_y;

	v_x = ((int)mlx->player->x / TILL_S) * TILL_S;
	init_step(mlx, &v_x, 'v');
	v_y = mlx->player->y + (v_x - mlx->player->x) * tan(mlx->ray->ray_angle);
	if ((check_neg_step(mlx, 0) && mlx->ray->step_y < 0)
		|| (!check_neg_step(mlx, 0) && mlx->ray->step_y > 0))
		mlx->ray->step_y *= -1;
	while (hit_wall(mlx, v_x - mlx->ray->pix, v_y))
	{
		v_x += mlx->ray->step_x;
		v_y += mlx->ray->step_y;
	}
	mlx->ray->step_x = v_x;
	mlx->ray->step_y = v_y;
	return (pythagoras(mlx, mlx->ray->step_x, mlx->ray->step_y));
}

void	fov_details(t_mlx *mlx)
{
	int	i;

	i = 0;
	mlx->ray->ray_angle = mlx->player->angle - (((FOV / 2) * PI) / 180);
	if (mlx->ray->ray_angle < 0)
		mlx->ray->ray_angle += 2 * PI;
	while (i < RAYS)
	{
		mlx->ray->h_hit = 0;
		find_ray_lenght(mlx);
		draw_wall(mlx, i);
		mlx->ray->ray_angle += ((FOV * PI) / 180) / RAYS;
		if (mlx->ray->ray_angle > 2 * PI)
			mlx->ray->ray_angle -= 2 * PI;
		i++;
	}
	if (mlx->player->minimap == 1)
		draw_minimap(mlx);
}
