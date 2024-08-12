/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:25:19 by bapasqui          #+#    #+#             */
/*   Updated: 2024/08/12 20:40:28 by bapasqui         ###   ########.fr       */
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

int	select_color(t_mlx *mlx, int x, int y)
{
	int	color;

	if (mlx->ray->h_hit)
	{
		if (mlx->ray->ray_angle > 0 && mlx->ray->ray_angle < PI)
			color = mlx_get_image_pixel(mlx->mlx, mlx->img_s->img, x, y);
		else
			color = mlx_get_image_pixel(mlx->mlx, mlx->img_n->img, x, y);
	}
	else
	{
		if (mlx->ray->ray_angle > (PI / 2) && mlx->ray->ray_angle < (3 * PI
				/ 2))
			color = mlx_get_image_pixel(mlx->mlx, mlx->img_e->img, x, y);
		else
			color = mlx_get_image_pixel(mlx->mlx, mlx->img_w->img, x, y);
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
        if (mlx->ray->ray_angle > (PI / 2) && mlx->ray->ray_angle < (3 * PI / 2))
            return (mlx->img_e->t_wid - wall_x * mlx->img_e->t_wid);
        else
            return (wall_x * mlx->img_w->t_wid);
    }
}
