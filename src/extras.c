/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:51:16 by bapasqui          #+#    #+#             */
/*   Updated: 2024/07/08 22:38:06 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_put_image(t_mlx *mlx, int x, int y, void *img);

void	print_banner(t_mlx *mlx)
{
	my_put_image(mlx, 0, 483, mlx->wall);
}

void	my_put_image(t_mlx *mlx, int x, int y, void *img)
{
	int	width;
	int	height;

	int i, j;
	i = 0;
	width = 920;
	height = 100;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, x + j, y + i,
				mlx_get_image_pixel(mlx->mlx, img, j, i));
			j++;
		}
		i++;
	}
}
