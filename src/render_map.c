/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:25:15 by bapasqui          #+#    #+#             */
/*   Updated: 2024/06/18 23:01:30 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int attribute_data_map(t_mlx *mlx)
{
	int i;
	
	i = 0;
	while(mlx->map->file[i])
	{
		if (!ft_strncmp(mlx->map->file[i], "NO", 2))
			mlx->map->data_map->no = ft_strdup(mlx->map->file[i] + 3);
		else if (!ft_strncmp(mlx->map->file[i], "SO", 2))
			mlx->map->data_map->so = ft_strdup(mlx->map->file[i] + 3);
		else if (!ft_strncmp(mlx->map->file[i], "WE", 2))
			mlx->map->data_map->we = ft_strdup(mlx->map->file[i] + 3);
		else if (!ft_strncmp(mlx->map->file[i], "EA", 2))
			mlx->map->data_map->ea = ft_strdup(mlx->map->file[i] + 3);
		else if (!ft_strncmp(mlx->map->file[i], "F", 1))
			mlx->map->data_map->floor_char = ft_strdup(mlx->map->file[i] + 2);
		else if (!ft_strncmp(mlx->map->file[i], "C", 1))
			mlx->map->data_map->sky_char = ft_strdup(mlx->map->file[i] + 2);			
		else if (mlx->map->file[i][0] == '1' || mlx->map->file[i][0] == '0')
			break ;
		i++;
	}
	if (check_data_map(mlx->map->data_map))
		return (ERROR);
	mlx->map->start_map = i;
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

int read_file(t_mlx *mlx)
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

void	draw_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map->map[i])
	{
		j = 0;
		while (mlx->map->map[i][j])
		{
			if (mlx->map->map[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wall, j * 32, i
					* 32);
			j++;
		}
		i++;
	}
	mlx->map->data_map->width = j;
	mlx->map->data_map->height = i;
}
