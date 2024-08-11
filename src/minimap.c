/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:26:40 by qdeviann          #+#    #+#             */
/*   Updated: 2024/08/11 22:00:27 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_square2(t_mlx *mlx, t_xy *xy, t_xy *ij, int color)
{
	while (xy->x > (ij->y * 10))
	{
		mlx_set_image_pixel(mlx->mlx, mlx->minimap->img, xy->x + 5, xy->y,
			color);
		xy->x--;
	}
	while (xy->y > (ij->x * 10))
	{
		mlx_set_image_pixel(mlx->mlx, mlx->minimap->img, (ij->y * 10) + 5,
			xy->y, color);
		xy->y--;
	}
}

void	draw_square(t_mlx *mlx, int j, int i, int color)
{
	int	x;
	int	y;

	x = j * 10;
	y = i * 10;
	while (x < (((j + 1) * 10)))
	{
		mlx_set_image_pixel(mlx->mlx, mlx->minimap->img, x + 5, (i * 10),
			color);
		x++;
	}
	while (y < (((i + 1) * 10)))
	{
		mlx_set_image_pixel(mlx->mlx, mlx->minimap->img, x + 5, y, color);
		y++;
	}
	draw_square2(mlx, &(t_xy){x, y}, &(t_xy){i, j}, color);
}

void	draw_minimap(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	mlx->minimap->t_wid = (int)ft_strlen(mlx->map->map[0]) * 10;
	mlx->minimap->t_hei = get_width(mlx->map->map) * 10;
	mlx->minimap->img = mlx_new_image(mlx->mlx, mlx->minimap->t_wid,
			mlx->minimap->t_hei);
	while (mlx->map->map[i])
	{
		j = 0;
		while (mlx->map->map[i][j])
		{
			if (mlx->map->map[i][j] == '1')
				draw_square(mlx, j, i, 0xffffffff);
			j++;
		}
		i++;
	}
	draw_square(mlx, mlx->player->x / TILL_S, mlx->player->y / TILL_S,
		0xff00ff00);
	my_put_image(mlx, &(t_xy){10, 10}, &(t_wh){mlx->minimap->t_wid,
		mlx->minimap->t_hei, 1}, mlx->minimap->img);
	mlx_destroy_image(mlx->mlx, mlx->minimap->img);
}
