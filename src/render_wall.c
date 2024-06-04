/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:25:19 by bapasqui          #+#    #+#             */
/*   Updated: 2024/06/04 13:58:49 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    draw_wall(t_mlx *mlx, double x, double y, int r)
{
	int	i;
	int j;
	int	co;
	int	ca;
	double rapport;

	i = 0;
	co = x - mlx->player->x;
	ca = mlx->player->y - y;
	mlx->ray->dist = sqrt((co^2) + (ca^2));
	rapport = mlx->ray->dist * 920 / 40;
	j = 580;
	while (j > rapport)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, r, j, 0xFF2E86C1);
		j--;
	}
}