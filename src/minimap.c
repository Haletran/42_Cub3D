/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:26:40 by qdeviann          #+#    #+#             */
/*   Updated: 2024/08/01 13:26:45 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    draw_boy(t_mlx *mlx)
{
     draw_square(mlx, mlx->minimap->img, ((mlx->player->x / 32) * 12), (mlx->player->y / 32) * 12, 0xff00ff00);
}

void    draw_square(t_mlx *mlx, void *img, int x, int y, int color)
{
    int i;

    i = 0;
    while(i < 10)
    {
        mlx_set_image_pixel(mlx->mlx, img, x, y, color);
        x++;
        i++;
    }
    while(i > 0)
    {
        mlx_set_image_pixel(mlx->mlx, img, x, y, color);
        y++;
        i--;
    }
    while(i < 10)
    {
        mlx_set_image_pixel(mlx->mlx, img, x, y, color);
        x--;
        i++;
    }
    while(i > 0)
    {
        mlx_set_image_pixel(mlx->mlx, img, x, y, color);
        y--;
        i--;
    }
}

void    draw_minimap(t_mlx *mlx)
{
    int    i;
    int    j;

    i = 0;
    mlx->minimap->t_wid = (int)ft_strlen(mlx->map->map[0]) * 12;
    mlx->minimap->t_hei = get_width(mlx->map->map) * 12;
    mlx->minimap->img = mlx_new_image(mlx->mlx, mlx->minimap->t_wid, mlx->minimap->t_hei);
    while(mlx->map->map[i])
    {
        j = 0;
        while(mlx->map->map[i][j])
        {
            if(mlx->map->map[i][j] == '1')
                draw_square(mlx, mlx->minimap->img, (j * 12) + 5, (i * 12) - 5, 0xffffffff);
            j++;
        }
        i++;
    }
    draw_boy(mlx);
    my_put_image(mlx, &(t_xy ){10, 10}, &(t_wh){mlx->minimap->t_wid, mlx->minimap->t_hei}, mlx->minimap->img, 0);
    mlx_destroy_image(mlx->mlx, mlx->minimap->img);
}
