/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:25:19 by bapasqui          #+#    #+#             */
/*   Updated: 2024/07/14 19:24:31 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	pythagoras(t_mlx *mlx, float x, float y)
{
	float	a_s;
	float	o_s;
	float	hypo;

	a_s = x - mlx->player->x;
	o_s = y - mlx->player->y;
	hypo = sqrt((a_s * a_s) + (o_s * o_s));
	return (hypo);
}

float	keep_circle(float angle)
{
	if (angle < 0)
		angle += 2 * PI;
	if (angle > 2 * PI)
		angle -= 2 * PI;
	return (angle);
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

int	select_color(t_mlx *mlx, int x, int y)
{
	int	color;

	if (mlx->ray->h_hit)
	{
		if (mlx->ray->ray_angle > 0 && mlx->ray->ray_angle < PI)
			color = mlx_get_image_pixel(mlx->mlx, mlx->img_s->img, x, y);
				// south
		else
			color = mlx_get_image_pixel(mlx->mlx, mlx->img_n->img, x, y);
				// north
	}
	else
	{
		if (mlx->ray->ray_angle > (PI / 2) && mlx->ray->ray_angle < (3 * PI
				/ 2))
			color = mlx_get_image_pixel(mlx->mlx, mlx->img_e->img, x, y);
				// east
		else
			color = mlx_get_image_pixel(mlx->mlx, mlx->img_w->img, x, y);
				// west
	}
	return (color);
}

float	calculate_step(t_mlx *mlx)
{
	if (mlx->ray->h_hit)
	{
		if (mlx->ray->ray_angle > 0 && mlx->ray->ray_angle < PI)
			return (mlx->img_s->t_hei / mlx->ray->h_height);
		else
			return (mlx->img_n->t_hei / mlx->ray->h_height);
	}
	else
	{
		if (mlx->ray->ray_angle > (PI / 2) && mlx->ray->ray_angle < (3 * PI
				/ 2))
			return (mlx->img_e->t_hei / mlx->ray->h_height);
		else
			return (mlx->img_w->t_hei / mlx->ray->h_height);
	}
}

int	calculate_tex_x(t_mlx *mlx, float wall_x)
{
	if (mlx->ray->h_hit)
	{
		if (mlx->ray->ray_angle > 0 && mlx->ray->ray_angle < PI)
			return (wall_x * mlx->img_s->t_wid);
		else
			return (wall_x * mlx->img_n->t_wid);
	}
	else
	{
		if (mlx->ray->ray_angle > (PI / 2) && mlx->ray->ray_angle < (3 * PI
				/ 2))
			return (wall_x * mlx->img_e->t_wid);
		else
			return (wall_x * mlx->img_e->t_wid);
	}
}

void	draw_in_color(t_mlx *mlx, int ray_index, float start, float end)
{
	int		color;
	float	wall_x;
	int		tex_x;
	float	tex_y;
	float	step;

	if (mlx->ray->h_hit)
		wall_x = (fmod(mlx->ray->x, 32) * 100 / 32) / 100;
	else
	{
		wall_x = (fmod(mlx->ray->y, 32) * 100 / 32) / 100;
	}
	tex_x = calculate_tex_x(mlx, wall_x);
	step = calculate_step(mlx);
	tex_y = (start - WINDOW_HEIGHT / 2 + mlx->ray->h_height / 2) / step;
	while (start < end)
	{
		color = select_color(mlx, tex_x, (int)tex_y);
		tex_y += step;
		mlx_pixel_put(mlx->mlx, mlx->win, ray_index, start, color);
		start++;
	}
}

void	draw_wall(t_mlx *mlx, int ray_index)
{
	float start;
	float end;
	float screen_x;

	mlx->player->eye_h = WINDOW_HEIGHT / 2;
	mlx->ray->dist *= cos(keep_circle(mlx->ray->ray_angle
				- mlx->player->angle));
	screen_x = (ray_index * WINDOW_WIDTH) / RAYS;
	mlx->ray->h_height = (32 / mlx->ray->dist) * ((WINDOW_WIDTH / 2) / tan(((FOV
						/ 2) * PI) / 180));
	start = mlx->player->eye_h - mlx->ray->h_height / 2;
	end = mlx->player->eye_h + mlx->ray->h_height / 2;
	draw_in_color(mlx, screen_x, start, end);
	draw_other(mlx, screen_x, start, end);
}