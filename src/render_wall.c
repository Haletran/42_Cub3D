/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:25:19 by bapasqui          #+#    #+#             */
/*   Updated: 2024/06/25 15:31:21 by bapasqui         ###   ########.fr       */
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
	float origin;

	origin = 0;
	while (origin < start)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, ray_index, origin, 0xFF5dade2);
		origin++;
	}
	while (end < WINDOW_HEIGHT)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, ray_index, end, 0xFFe5e8e8);
		end++;
	}
}

int select_color(t_mlx *mlx, float pos)
{
    int color;
    float wall_x;

    if (mlx->ray->h_hit)
    {
        wall_x = fmod(mlx->ray->x, 32);
		if(mlx->ray->ray_angle > 0 && mlx->ray->ray_angle < PI)
            color = 0xFFd0d3d4;//south
		else
            color = mlx->img_n->pix_map[(int)(pos * (mlx->img_n->size_line / 32) + wall_x)];//north
    }
    else
    {
        //wall_x = mlx->ray->y + mlx->ray->dist * sin(mlx->ray->ray_angle);
        if(mlx->ray->ray_angle > (PI / 2) && mlx->ray->ray_angle < (3 * PI / 2))
            color = 0xFF2874a6;//east
        else
            color = 0xFF34495e;//west
    }
    return color;
}

void	draw_in_color(t_mlx *mlx, int ray_index, float start, float end)
{
	int color;
	float pos;
	float line_height;

	line_height = end - start;
	pos = (line_height / mlx->img_n->t_hei);
	while(start < end)
	{
		color = select_color(mlx, pos);
		mlx_pixel_put(mlx->mlx, mlx->win, ray_index, start, color);
		start++;
		pos++;
	}
}

void	draw_wall(t_mlx *mlx, int ray_index)
{
	float	start;
	float	end;
	float	h;
	float	screen_x;

	mlx->player->eye_h = WINDOW_HEIGHT / 2;
	mlx->ray->dist *= cos(keep_circle(mlx->ray->ray_angle - mlx->player->angle));
	screen_x = (ray_index * WINDOW_WIDTH) / RAYS;
	h = (32 / mlx->ray->dist) * ((WINDOW_WIDTH / 2) / tan(((FOV / 2) * PI) / 180));
	start = mlx->player->eye_h - h / 2;
	if (start < 0)
		start = 0;
	end = mlx->player->eye_h + h / 2;
	if (end >= WINDOW_HEIGHT)
		end = WINDOW_HEIGHT;
	draw_in_color(mlx, screen_x, start, end);
	draw_other(mlx, screen_x, start, end);
}