/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <qdeviann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:52:00 by bapasqui          #+#    #+#             */
/*   Updated: 2024/08/12 09:20:41 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_put_image(t_mlx *mlx, t_xy *xy, t_wh *whc, void *img)
{
	int	color;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < whc->h)
	{
		j = 0;
		while (j < whc->w)
		{
			color = mlx_get_image_pixel(mlx->mlx, img, j, i);
			if (color == 0)
				mlx_pixel_put(mlx->mlx, mlx->win, xy->y + j, xy->x + i, 0xA07BADCD);
			if (whc->check == 1 && color != 0)
				mlx_pixel_put(mlx->mlx, mlx->win, xy->y + j, xy->x + i, color);
			else if (whc->check == 0)
				mlx_pixel_put(mlx->mlx, mlx->win, xy->y + j, xy->x + i, color);
			j++;
		}
		i++;
	}
}

char	**ft_copy_tab(char **src, int size)
{
	int		i;
	char	**dest;

	i = 0;
	dest = ft_calloc(size + 1, sizeof(char *));
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = ft_strdup(src[i]);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

int	get_width(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* int get_height(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_strlen(str[i]) > j)
			j = ft_strlen(str[i]);
		i++;
	}
	return (j);
} */

void	get_player_data(t_mlx *mlx, int i, int j, char c)
{
	if (c == 'N')
		mlx->player->angle = 3 * PI / 2;
	else if (c == 'S')
		mlx->player->angle = PI / 2;
	else if (c == 'E')
		mlx->player->angle = 0;
	else if (c == 'W')
		mlx->player->angle = PI;
	mlx->player->x = j * TILL_S + 16;
	mlx->player->y = i * TILL_S + 16;
}

int	check_neg_step(t_mlx *mlx, int h)
{
	if (h)
	{
		if (mlx->ray->ray_angle > (PI / 2) && mlx->ray->ray_angle < ((3 * PI)
				/ 2))
			return (1);
	}
	else
	{
		if (mlx->ray->ray_angle > 0 && mlx->ray->ray_angle < PI)
			return (1);
	}
	return (0);
}
