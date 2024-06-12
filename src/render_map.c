/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:25:15 by bapasqui          #+#    #+#             */
/*   Updated: 2024/06/05 23:07:24 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

int init_map(t_mlx *mlx)
{
	int	fd;
	int	i;

	i = 0;
	mlx->map->map = ft_calloc(sizeof(char *), mlx->map->lenght);
	if (!mlx->map->map)
		return (ft_error(MALLOC_ERROR));
	fd = open(mlx->map->path, O_RDONLY);
	if (!fd)
		return (ft_error(FD_ERROR));
	while (1)
	{
		mlx->map->map[i] = get_next_line(fd);
		if (!mlx->map->map[i])
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
/* 			else if (mlx->map->map[i][j] == '0' || mlx->map->map[i][j] == 'W')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->floor, j * 32,
					i * 32); */
/* 			else if (mlx->map->map[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->floor, j * 32,
					i * 32); */
			j++;
		}
		i++;
	}
	mlx->map->width = j;
	mlx->map->height = i;
}
