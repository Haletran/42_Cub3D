/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:25:19 by bapasqui          #+#    #+#             */
/*   Updated: 2024/06/05 23:07:26 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	pythagoras(t_mlx *mlx, double x, double y)
{
	double	a_s;
	double	o_s;
	double	hypo;

	a_s = x - mlx->player->x;
	o_s = y - mlx->player->y;
	hypo = sqrt((a_s * a_s) + (o_s * o_s));
	return (hypo);
}

// void	draw_wall(t_mlx *mlx, double x, double y, int ray_index)
// {
// 	double	i;
// 	double	h;
// 	int		screen_x;
// 	int 	tmp;

// 	mlx->ray->dist = pythagoras(mlx, x, y);
// 	mlx->player->eye_h = WINDOW_HEIGHT / 2;
// 	h = (32 / mlx->ray->dist) * ((WINDOW_WIDTH / 2) / tan(((FOV / 2) * PI) / 180));
// 	i = mlx->player->eye_h - h / 2;
// 	screen_x = (ray_index * WINDOW_WIDTH) / RAYS;
// 	tmp = 0;
// 	while (++tmp < mlx->player->eye_h)
// 		mlx_pixel_put(mlx->mlx, mlx->win, screen_x, tmp, 0xFF87CEEB);
// 	while (i < mlx->player->eye_h + h / 2)
// 	{
// 		if (i >= 0 && i < WINDOW_HEIGHT)
// 			mlx_pixel_put(mlx->mlx, mlx->win, screen_x, i, 0xFFBCC6CA);
// 		i++;
// 	}
// 	while (i < WINDOW_HEIGHT)
// 	{
// 		mlx_pixel_put(mlx->mlx, mlx->win, screen_x, i, 0xFF6B6C6D);
// 		i++;
// 	}
// }

void	draw_wall(t_mlx *mlx, int ray_index)
{
	double	i;
	double	h;
	int		screen_x;
	int 	tmp;

	mlx->player->eye_h = WINDOW_HEIGHT / 2;
	h = (32 / mlx->ray->dist) * ((WINDOW_WIDTH / 2) / tan(((FOV / 2) * PI) / 180));
	i = mlx->player->eye_h - h / 2;
	screen_x = (ray_index * WINDOW_WIDTH) / RAYS;
	tmp = 0;
	while (++tmp < mlx->player->eye_h)
		mlx_pixel_put(mlx->mlx, mlx->win, screen_x, tmp, 0xFF87CEEB);
	while (i < mlx->player->eye_h + h / 2)
	{
		if (i >= 0 && i < WINDOW_HEIGHT)
			mlx_pixel_put(mlx->mlx, mlx->win, screen_x, i, 0xFFBCC6CA);
		i++;
	}
	while (i < WINDOW_HEIGHT)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, screen_x, i, 0xFF6B6C6D);
		i++;
	}
}