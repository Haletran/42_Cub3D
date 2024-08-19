/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:20:26 by bapasqui          #+#    #+#             */
/*   Updated: 2024/08/19 18:50:36 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_strlen_color(char *color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (color[i])
	{
		if (color[i] != ' ')
			j++;
		i++;
	}
	return (j);
}

int	check_map(t_mlx **mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((*mlx)->map->map[i])
	{
		j = 0;
		while ((*mlx)->map->map[i][j])
		{
			if (check_if_charset((*mlx)->map->map[i][j],
				"NSEW10 \n\0") == ERROR)
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	attribute_color(t_mlx *mlx)
{
	if (check_color(mlx->map->data_map->floor_char) == ERROR)
		return (ERROR);
	if (check_color(mlx->map->data_map->sky_char) == ERROR)
		return (ERROR);
	mlx->map->data_map->floor_c = rgb_to_hex(mlx->map->data_map->floor_char);
	if (mlx->map->data_map->floor_c == ERROR)
		return (ERROR);
	mlx->map->data_map->sky_c = rgb_to_hex(mlx->map->data_map->sky_char);
	if (mlx->map->data_map->sky_c == ERROR)
		return (ERROR);
	return (SUCCESS);
}

void	process_map_character(t_mlx **mlx, bool *find_zero, char **tmp,
		t_xy *ij)
{
	if ((*mlx)->map->map[ij->x][ij->y] == '1')
		tmp[ij->x][ij->y] = '1';
	else if ((*mlx)->map->map[ij->x][ij->y] == '0')
	{
		*find_zero = true;
		tmp[ij->x][ij->y] = '0';
	}
	else if (check_if_charset((*mlx)->map->map[ij->x][ij->y],
		"NSEW") == SUCCESS)
		tmp[ij->x][ij->y] = (*mlx)->map->map[ij->x][ij->y];
	else if ((*mlx)->map->map[ij->x][ij->y] == 32)
		tmp[ij->x][ij->y] = '1';
}
