/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:52:00 by bapasqui          #+#    #+#             */
/*   Updated: 2024/07/28 22:58:55 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_put_image(t_mlx *mlx, t_xy *xy, t_wh *wh, void *img, int check)
{
    int	width;
    int	height;

    int i, j;
    i = 0;
    width = wh->w;
    height = wh->h;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            int color = mlx_get_image_pixel(mlx->mlx, img, j, i);
            if (check == 1 && color != 0)
                mlx_pixel_put(mlx->mlx, mlx->win, xy->y + j, xy->x + i, color);
            else if (check == 0)
                mlx_pixel_put(mlx->mlx, mlx->win, xy->y + j, xy->x + i, color);
            j++;
        }
        i++;
    }
}