/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapt <bapt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:26:40 by qdeviann          #+#    #+#             */
/*   Updated: 2024/08/09 00:53:23 by bapt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_square(t_mlx *mlx, int j, int i, int color)
{
	int	x;
	int	y;

	x = j * 10;
	y = i * 10;
	while(x < (((j + 1) * 10)))
	{
		mlx_set_image_pixel(mlx->mlx, mlx->minimap->img, x + 5, (i * 10), color);
		x++;
	}
	while(y < (((i + 1) * 10)))
	{
		mlx_set_image_pixel(mlx->mlx, mlx->minimap->img, x + 5, y, color);
		y++;
	}
	while(x > (j * 10))
	{
		mlx_set_image_pixel(mlx->mlx, mlx->minimap->img, x + 5, y, color);
		x--;
	}
	while(y > (i * 10))
	{
		mlx_set_image_pixel(mlx->mlx, mlx->minimap->img, (j * 10) + 5, y, color);
		y--;
	}
}

void    draw_minimap(t_mlx *mlx)
{
    int    i;
    int    j;

    i = 0;
    mlx->minimap->t_wid = (int)ft_strlen(mlx->map->map[0]) * 10;
    mlx->minimap->t_hei = get_width(mlx->map->map) * 10;
    mlx->minimap->img = mlx_new_image(mlx->mlx, mlx->minimap->t_wid, mlx->minimap->t_hei);
    while(mlx->map->map[i])
    {
        j = 0;
        while(mlx->map->map[i][j])
        {
            if(mlx->map->map[i][j] == '1')
                draw_square(mlx, j, i, 0xffffffff);
            j++;
        }
        i++;
    }
	draw_square(mlx, mlx->player->x / TILL_S, mlx->player->y / TILL_S, 0xff00ff00);
    my_put_image(mlx, &(t_xy ){10, 10}, &(t_wh){mlx->minimap->t_wid, mlx->minimap->t_hei}, mlx->minimap->img, 1);
    mlx_destroy_image(mlx->mlx, mlx->minimap->img);
}
