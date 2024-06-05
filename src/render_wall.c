/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:25:19 by bapasqui          #+#    #+#             */
/*   Updated: 2024/06/04 14:02:32 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void    draw_wall(t_mlx *mlx, double x, double y, int r)
{
	double	i;
	double	j;
	double	co;
	double	ca;
	double	h;

	mlx->player->eye_h = WINDOW_HEIGHT / 2;
	co = x - mlx->player->x;
	ca = y - mlx->player->y;
	if (co < 0)
		co *= -1;
	if (ca < 0)
		ca *= -1;
	mlx->ray->dist = sqrt(((int)co^2) + ((int)ca^2)) * 10;
	h = (32 / mlx->ray->dist) * ((WINDOW_WIDHT / 2) / tan(((FOV / 2) * PI) / 180));
	i = mlx->player->eye_h - h / 2;
	j = 0;
	while (j < i)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, r, j, 0xFF5FA2DE);
		j++;
	}
	while (i <= h)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, r, i, 0xFF6B6C6D);
		i++;
	}
	while (i < WINDOW_HEIGHT)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, r, i, 0xFFBCC6CA);
		i++;
	}
}
