/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapt <bapt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:52:00 by bapasqui          #+#    #+#             */
/*   Updated: 2024/07/31 01:10:56 by bapt             ###   ########.fr       */
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

char **ft_copy_tab(char **src, char **dest)
{
	int i;

	i = 0;
    dest = ft_calloc(get_width(src) + 1, sizeof(char *));
	while (src[i])
	{
		dest[i] = ft_strdup(src[i]);
		i++;
	}
	return (dest);
}

int get_width(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int get_maxlenght(char **str)
{
	int i;
	int j;
	int max;

	i = 0;
	max = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			j++;
		if (j > max)
			max = j;
		i++;
	}
	return (max + 1);
}