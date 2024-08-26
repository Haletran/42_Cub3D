/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapt <bapt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:25:15 by bapasqui          #+#    #+#             */
/*   Updated: 2024/08/26 12:53:47 by bapt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	assign_data_map(char *map, char *prefix, char **target)
{
	char	*tmp;

	if (!ft_strncmp(map, prefix, ft_strlen(prefix)))
	{
		tmp = *target;
		*target = ft_strtrim(map + ft_strlen(prefix), " \n	");
		free(tmp);
		return (1);
	}
	return (0);
}

int	attribute_data_map(t_mlx *mlx)
{
	int	assign;

	assign = 0;
	mlx->counter = 0;
	while (mlx->map->file[mlx->counter])
	{
		assign += assign_data_map(mlx->map->file[mlx->counter], "NO",
				&mlx->map->data_map->no);
		assign += assign_data_map(mlx->map->file[mlx->counter], "SO",
				&mlx->map->data_map->so);
		assign += assign_data_map(mlx->map->file[mlx->counter], "WE",
				&mlx->map->data_map->we);
		assign += assign_data_map(mlx->map->file[mlx->counter], "EA",
				&mlx->map->data_map->ea);
		assign += assign_data_map(mlx->map->file[mlx->counter], "F",
				&mlx->map->data_map->floor_char);
		assign += assign_data_map(mlx->map->file[mlx->counter], "C",
				&mlx->map->data_map->sky_char);
		if (assign == 6)
			break ;
		mlx->counter++;
	}
	if (check_data_map(mlx->map->data_map))
		return (ERROR);
	return (SUCCESS);
}

int	get_map_len(char *path)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_error(FD_ERROR));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		i++;
	}
	free(line);
	close(fd);
	return (i + 1);
}

int	read_file(t_mlx *mlx)
{
	int	fd;
	int	i;

	i = 0;
	mlx->map->file = ft_calloc(sizeof(char *), mlx->map->file_lenght);
	if (!mlx->map->file)
		return (ft_error(MALLOC_ERROR));
	fd = open(mlx->map->path, O_RDONLY);
	if (!fd)
		return (ft_error(FD_ERROR));
	while (1)
	{
		mlx->map->file[i] = get_next_line(fd);
		if (!mlx->map->file[i])
			break ;
		i++;
	}
	close(fd);
	return (SUCCESS);
}
