/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:21:15 by baptiste          #+#    #+#             */
/*   Updated: 2024/08/19 16:37:04 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_color(char *color)
{
	int	i;
	int	comma_count;

	i = 0;
	comma_count = 0;
	if (ft_strlen_color(color) <= 0 || ft_strlen_color(color) > 11)
		return (ERROR);
	while (color[i])
	{
		if (!(color[i] >= '0' && color[i] <= '9') && color[i] != ','
			&& color[i] != ' ')
			return (ERROR);
		if (color[i] == ',')
		{
			if (color[i + 1] && check_if_charset(color[i + 1],
					"0123456789 ") == ERROR)
				return (ERROR);
			comma_count++;
		}
		i++;
	}
	if (comma_count != 2)
		return (ERROR);
	return (SUCCESS);
}

int	check_map_validity(t_mlx *mlx, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (check_if_charset(mlx->map->map[i][j], "NSEW") == SUCCESS)
				get_player_data(mlx, i, j, mlx->map->map[i][j]);
			if (check_if_charset(mlx->map->map[i][j], "01NSEW3 \n") == ERROR)
				return (ERROR);
			j++;
		}
		i++;
	}
	mlx->map->data_map->width = j;
	mlx->map->data_map->height = i;
	if (attribute_color(mlx))
		return (ERROR);
	return (SUCCESS);
}

int	check_data_map(t_data_map *data_map)
{
	if (!data_map->no || !data_map->so || !data_map->we || !data_map->ea
		|| !data_map->floor_char || !data_map->sky_char)
		return (ft_error(DATA_ERROR));
	if (access(data_map->no, F_OK) == -1 || access(data_map->so, F_OK) == -1
		|| access(data_map->we, F_OK) == -1 || access(data_map->ea, F_OK) == -1)
		return (ft_error(PATH_ERROR));
	return (SUCCESS);
}

int	replace_space(t_mlx **mlx)
{
	int		i;
	int		j;
	bool	find_zero;
	char	**tmp;

	i = 0;
	find_zero = false;
	tmp = create_tmp_map((*mlx)->map->map);
	while ((*mlx)->map->map[i])
	{
		j = 0;
		while ((*mlx)->map->map[i][j])
		{
			process_map_character(mlx, &find_zero, tmp, &(t_xy){i, j});
			j++;
		}
		find_zero = false;
		i++;
	}
	i = get_width((*mlx)->map->map);
	free_tab((*mlx)->map->map);
	(*mlx)->map->map = ft_copy_tab(tmp, i + 1);
	free_tab(tmp);
	return (SUCCESS);
}

int	init_map(t_mlx **mlx)
{
	int	i;
	int	j;

	i = (*mlx)->map->start_map + 1;
	j = 0;
	(*mlx)->map->map = ft_calloc(sizeof(char *), (*mlx)->map->file_lenght);
	if (!(*mlx)->map->map)
		return (ft_error(MALLOC_ERROR));
	while ((*mlx)->map->file[i])
	{
		(*mlx)->map->map[j] = ft_strdup((*mlx)->map->file[i]);
		j++;
		i++;
	}
	free_tab((*mlx)->map->file);
	(*mlx)->map->file = NULL;
	(*mlx)->map->map[j] = NULL;
	if (check_map(mlx))
		return (ft_error(MAP_ERROR));
	replace_space(mlx);
	return (SUCCESS);
}
