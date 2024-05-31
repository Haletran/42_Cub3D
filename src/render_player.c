/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:25:19 by bapasqui          #+#    #+#             */
/*   Updated: 2024/05/23 15:54:36 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//void draw_line(t_mlx *mlx, int x0, int y0, int x1, int y1, int color)
//{
//    int dx = abs(x1 - x0);
//    int sx = x0 < x1 ? 1 : -1;
//    int dy = -abs(y1 - y0);
//    int sy = y0 < y1 ? 1 : -1;
//    int err = dx + dy;
//    int e2;
//
//    while (1)
//    {
    //    mlx_pixel_put(mlx->mlx, mlx->win, x0, y0, color);
    //    if (x0 == x1 && y0 == y1)
    //        break;
    //    e2 = 2 * err;
    //    if (e2 >= dy)
    //    {
    //        err += dy;
    //        x0 += sx;
    //    }
    //    if (e2 <= dx)
    //    {
    //        err += dx;
    //        y0 += sy;
//        }
//    }
//}
//
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