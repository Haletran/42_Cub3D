/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_on_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapt <bapt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:45:33 by bapasqui          #+#    #+#             */
/*   Updated: 2024/07/31 01:40:29 by bapt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void draw_debug(t_mlx *mlx, t_xy *xy, t_wh *wh)
{
    int i;
    int j;

    i = 0;
    j = 0;
    mlx->debug_box = mlx_new_image(mlx->mlx, wh->w, wh->h);
    i = 0;
    j = 0;
    while (i < wh->h)
    {
        j = 0;
        while (j < wh->w)
        {
            
            if (i == 0 || i == wh->h - 1 || j == 0 || j == wh->w - 1)
                mlx_set_image_pixel(mlx->mlx, mlx->debug_box, j, i, 0xFFFFFFFF);
            j++;
        }
        i++;
    }
    my_put_image(mlx, xy, wh, mlx->debug_box, 0);
    mlx_string_put(mlx->mlx, mlx->win, xy->y + 10, xy->x + 20, 0x00FF0a42db, " DEBUG :");
    mlx_string_put(mlx->mlx, mlx->win, xy->y + 10, xy->x + 40, 0XFFFFFFFF, ft_strjoin("x = ", ft_itoa(mlx->player->x)));
    mlx_string_put(mlx->mlx, mlx->win, xy->y + 10, xy->x + 60, 0x00FFFFFFFF, ft_strjoin("y = ", ft_itoa(mlx->player->y)));
    mlx_string_put(mlx->mlx, mlx->win, xy->y + 10, xy->x + 80, 0x00FFFFFFFF, ft_strjoin("angle = ", ft_itoa(mlx->player->angle)));
    mlx_string_put(mlx->mlx, mlx->win, xy->y + 10, xy->x + 100, 0x00FFFFFFFF, ft_strjoin("delta_x = ", ft_itoa(mlx->player->delta_x)));
    mlx_string_put(mlx->mlx, mlx->win, xy->y + 10, xy->x + 120, 0x00FFFFFFFF, ft_strjoin("delta_y = ", ft_itoa(mlx->player->delta_y)));
    mlx_destroy_image(mlx->mlx, mlx->debug_box);
}
