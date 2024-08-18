/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <qdeviann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 21:00:00 by bapasqui          #+#    #+#             */
/*   Updated: 2024/08/18 18:16:25 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_in_color(t_mlx *mlx, int ray_index, float start, float end)
{
	int		color;
	float	wall_x;
	int		tex_x;
	float	tex_y;
	float	step;

	if (mlx->ray->h_hit)
		wall_x = (fmod(mlx->ray->x, TILL_S) * 100 / TILL_S) / 100;
	else
	{
		wall_x = (fmod(mlx->ray->y, TILL_S) * 100 / TILL_S) / 100;
	}
	tex_x = calculate_tex_x(mlx, wall_x);
	step = calculate_step(mlx);
	tex_y = (start - WINDOW_HEIGHT / 2 + mlx->ray->h_height / 2) / step;
	while (start < end)
	{
		color = select_color(mlx, tex_x, (int)tex_y);
		tex_y += step;
		if (ray_index < RAYS && start < WINDOW_HEIGHT)
			mlx_pixel_put(mlx->mlx, mlx->win, ray_index, start, color);
		start++;
	}
}

void	draw_wall(t_mlx *mlx, int ray_index)
{
	float	start;
	float	end;
	float	screen_x;

	mlx->player->eye_h = WINDOW_HEIGHT / 2;
	mlx->ray->dist *= cos(keep_circle(mlx->ray->ray_angle
				- mlx->player->angle));
	screen_x = (ray_index * WINDOW_WIDTH) / RAYS;
	mlx->ray->h_height = (TILL_S / mlx->ray->dist) * ((WINDOW_WIDTH / 2)
			/ tan(((FOV / 2) * PI) / 180));
	start = mlx->player->eye_h - mlx->ray->h_height / 2;
	end = mlx->player->eye_h + mlx->ray->h_height / 2;
	draw_in_color(mlx, screen_x, start, end);
	draw_other(mlx, screen_x, start, end);
}

void	draw_other(t_mlx *mlx, int ray_index, float start, float end)
{
	float	origin;

	origin = 0;
	while (origin < start)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, ray_index, origin,
			mlx->map->data_map->sky_c);
		origin++;
	}
	while (end < WINDOW_HEIGHT)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, ray_index, end,
			mlx->map->data_map->floor_c);
		end++;
	}
}

void	draw_ray(t_mlx *mlx)
{
	int	x;
	int	y;
	int	j;
	int	color;

	x = mlx->player->x;
	y = mlx->player->y;
	j = 0;
	while (j < mlx->ray->dist)
	{
		x = mlx->player->x + j * cos(mlx->ray->ray_angle);
		y = mlx->player->y + j * sin(mlx->ray->ray_angle);
		if (x < 0 || y < 0 || x > mlx->map->data_map->width * TILL_S
			|| y > mlx->map->data_map->height * TILL_S)
			break ;
		color = 0x00FF00;
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, color);
		j++;
	}
}
