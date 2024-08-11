/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:21:15 by baptiste          #+#    #+#             */
/*   Updated: 2024/08/11 21:47:11 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
			j++;
		}
		i++;
	}
	mlx->map->data_map->width = j;
	mlx->map->data_map->height = i;
	mlx->map->data_map->floor_c = rgb_to_hex(mlx->map->data_map->floor_char);
	mlx->map->data_map->sky_c = rgb_to_hex(mlx->map->data_map->sky_char);
	mlx->map->data_map->floor_char = free_char(mlx->map->data_map->floor_char);
	mlx->map->data_map->sky_char = free_char(mlx->map->data_map->sky_char);
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

int	replace_space(t_mlx *mlx)
{
	int		i;
	int		j;
	bool	find_zero;
	char	**tmp;

	i = 0;
	j = 0;
	find_zero = false;
	tmp = create_tmp_map(mlx->map->map);
	while (mlx->map->map[i])
	{
		j = 0;
		while (mlx->map->map[i][j])
		{
			if (mlx->map->map[i][j] == '1')
				tmp[i][j] = '1';
			else if (mlx->map->map[i][j] == '0')
			{
				find_zero = true;
				tmp[i][j] = '0';
			}
			else if (mlx->map->map[i][j] == 'N' || mlx->map->map[i][j] == 'S'
				|| mlx->map->map[i][j] == 'E' || mlx->map->map[i][j] == 'W')
				tmp[i][j] = mlx->map->map[i][j];
			else if (mlx->map->map[i][j] == 32 && find_zero == true)
				tmp[i][j] = '1';
			j++;
		}
		find_zero = false;
		i++;
	}
	free_tab(mlx->map->map);
	mlx->map->map = ft_copy_tab(tmp);
	free_tab(tmp);
	return (SUCCESS);
}

int	init_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = mlx->map->start_map;
	j = 0;
	mlx->map->map = ft_calloc(sizeof(char *), mlx->map->file_lenght + 1);
	if (!mlx->map->map)
		return (ft_error(MALLOC_ERROR));
	while (mlx->map->file[i])
	{
		mlx->map->map[j] = ft_strdup(mlx->map->file[i]);
		j++;
		i++;
	}
	free_tab(mlx->map->file);
	mlx->map->map[j] = NULL;
	replace_space(mlx);
	return (SUCCESS);
}
