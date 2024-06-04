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
	int		co;
	int		ca;
	double	h;

	mlx->player->eye_h = WINDOW_HEIGHT / 2;
	co = x - mlx->player->x;
	ca = mlx->player->y - y;
	mlx->ray->dist = sqrt((co^2) + (ca^2)) * 32;
	h = (32 / mlx->ray->dist) * ((WINDOW_WIDHT / 2) / tan(((FOV * PI) / 180) / 2));
	i = mlx->player->eye_h - h / 2;
	while (i < h)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, r, i, 0xFF2E86C1);
		i++;
	}
}