/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:52:00 by bapasqui          #+#    #+#             */
/*   Updated: 2024/07/28 22:41:29 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_put_image(t_mlx *mlx, t_xy *xy, t_wh *wh, void *img)
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
			mlx_pixel_put(mlx->mlx, mlx->win, xy->y + j, xy->x + i,
				mlx_get_image_pixel(mlx->mlx, img, j, i));
			j++;
		}
		i++;
	}
}