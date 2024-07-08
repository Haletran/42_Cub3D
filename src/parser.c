/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:21:15 by baptiste          #+#    #+#             */
/*   Updated: 2024/07/08 21:15:30 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int check_map_validity(t_mlx *mlx, char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
/*             if (check_if_charset(map[i][j], "012NSEW") == ERROR)
                return (ERROR); */
            if (check_if_charset(mlx->map->map[i][j], "NSEW") == SUCCESS)
				get_player_data(mlx, i, j, mlx->map->map[i][j]);
            j++;
        }
        i++;
    }
    return (SUCCESS);
}

int	check_data_map(t_data_map *data_map)
{
	data_map->we = ft_strtrim(data_map->we, " ");
	data_map->ea = ft_strtrim(data_map->ea, " ");
	data_map->so = ft_strtrim(data_map->so, " ");
	data_map->no = ft_strtrim(data_map->no, " ");
	data_map->we = ft_strtrim(data_map->we, "\n");
	data_map->ea = ft_strtrim(data_map->ea, "\n");
	data_map->so = ft_strtrim(data_map->so, "\n");
	data_map->no = ft_strtrim(data_map->no, "\n");
	if (!data_map->no || !data_map->so || !data_map->we || !data_map->ea
		|| !data_map->floor_char || !data_map->sky_char)
		return (ft_error(DATA_ERROR));
	if (access(data_map->no, F_OK) == -1 || access(data_map->so, F_OK) == -1
		|| access(data_map->we, F_OK) == -1 || access(data_map->ea, F_OK) == -1)
		return (ft_error(PATH_ERROR));
	return (SUCCESS);
}

int	init_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = mlx->map->start_map;
	j = 0;
	mlx->map->map = ft_calloc(sizeof(char *), mlx->map->file_lenght - i + 1);
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
	return (SUCCESS);
}

int	convert_rgb_to_hex(char *color)
{
	int a = 255;
	int r;
	int g;
	int b;

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