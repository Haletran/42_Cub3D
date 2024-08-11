/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 21:18:08 by bapasqui          #+#    #+#             */
/*   Updated: 2024/08/11 21:52:05 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_if_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (SUCCESS);
		i++;
	}
	return (ERROR);
}

int	get_maxlenght(char **str)
{
	int	i;
	int	j;
	int	max;

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

int	rgb_to_hex(char *color)
{
	int	a;
	int	r;
	int	g;
	int	b;

	a = 255;
	r = ft_atoi(color);
	while (*color && *color != ',')
		color++;
	color++;
	g = ft_atoi(color);
	while (*color && *color != ',')
		color++;
	color++;
	b = ft_atoi(color);
	return (a << 24 | r << 16 | g << 8 | b);
}

char	**create_tmp_map(char **map)
{
	int		i;
	int		max;
	int		j;
	int		width;
	char	**tmp;

	i = 0;
	width = get_width(map);
	max = get_maxlenght(map);
	tmp = ft_calloc(sizeof(char *), width + 2);
	if (!tmp)
		return (NULL);
	while (i < width + 1)
	{
		tmp[i] = ft_calloc(sizeof(char), max + 1);
		j = 0;
		while (j < max - 1)
		{
			tmp[i][j] = '3';
			j++;
		}
		tmp[i][j] = '\n';
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

void	find_ray_lenght(t_mlx *mlx)
{
	float	h_dist;
	float	v_dist;

	h_dist = get_horizontal_hit(mlx);
	v_dist = get_vertical_hit(mlx);
	if (h_dist < v_dist)
	{
		mlx->ray->h_hit = 1;
		mlx->ray->dist = h_dist;
	}
	else
	{
		mlx->ray->x = mlx->ray->step_x;
		mlx->ray->y = mlx->ray->step_y;
		mlx->ray->dist = v_dist;
	}
}
