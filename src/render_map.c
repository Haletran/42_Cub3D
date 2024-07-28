/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:25:15 by bapasqui          #+#    #+#             */
/*   Updated: 2024/07/28 22:55:28 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	attribute_data_map(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->map->file[i])
	{
		if (!ft_strncmp(mlx->map->file[i], "NO", 2))
			mlx->map->data_map->no = ft_strdup(mlx->map->file[i] + 2);
		else if (!ft_strncmp(mlx->map->file[i], "SO", 2))
			mlx->map->data_map->so = ft_strdup(mlx->map->file[i] + 2);
		else if (!ft_strncmp(mlx->map->file[i], "WE", 2))
			mlx->map->data_map->we = ft_strdup(mlx->map->file[i] + 2);
		else if (!ft_strncmp(mlx->map->file[i], "EA", 2))
			mlx->map->data_map->ea = ft_strdup(mlx->map->file[i] + 2);
		else if (!ft_strncmp(mlx->map->file[i], "F", 1))
			mlx->map->data_map->floor_char = ft_strdup(mlx->map->file[i] + 2);
		else if (!ft_strncmp(mlx->map->file[i], "C", 1))
			mlx->map->data_map->sky_char = ft_strdup(mlx->map->file[i] + 2);
		else if (mlx->map->data_map->no && mlx->map->data_map->so && mlx->map->data_map->we
			&& mlx->map->data_map->ea && mlx->map->data_map->floor_char && mlx->map->data_map->sky_char)
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

int	read_file(t_mlx *mlx)
{
	int	fd;
	int	i;
	int j;

	i = 0;
	j = 0;
	mlx->map->file = ft_calloc(sizeof(char *), mlx->map->file_lenght);
	if (!mlx->map->file)
		return (ft_error(MALLOC_ERROR));
	fd = open(mlx->map->path, O_RDONLY);
	if (!fd)
		return (ft_error(FD_ERROR));
	while (1)
	{
		mlx->map->file[i] = get_next_line(fd);
		j = 0;
		if (!mlx->map->file[i])
			break ;
		i++;
	}
	close(fd);
	return (SUCCESS);
}

int	check_if_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (SUCCESS);
		i++;
	}
	return (ERROR);
}

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
	mlx->player->x = j * 32 + 16;
	mlx->player->y = i * 32 + 16; 
}

void	draw_wallmap(t_mlx *mlx, int i, int j, int color, void *test)
{
	int	x;
	int	y;

	x = j * 10;
	y = i * 10;

	if (x > 150 || y > 150)
		return ;
	while(x < (((j + 1) * 10)))
	{
		mlx_set_image_pixel(mlx->mlx, test, x, (i * 10), color);
		x++;
	}
	while(y < (((i + 1) * 10)))
	{
		mlx_set_image_pixel(mlx->mlx, test, x, y, color);
		y++;
	}
	while(x > (j * 10))
	{
		mlx_set_image_pixel(mlx->mlx, test, x, y, color);
		x--;
	}
	while(y > (i * 10))
	{
		mlx_set_image_pixel(mlx->mlx, test, (j * 10), y, color);
		y--;
	}
}

void	draw_map(t_mlx *mlx)
{
    int	i;
    int	j;
	int x;
	int y;
	int px;
	int py;
	int tmp;

	x = 0;
	px = 7;
	py = 7;

	mlx->minimap->img = mlx_new_image(mlx->mlx, 150, 150);
    i = mlx->player->y / 32 - 7;
	tmp = i;
	while(tmp <= 0)
	{
		tmp++;
		px--;
	}
	if (i < 0)
		i = 0;
	while(i < mlx->player->y / 32 + 7)
	{
		j = mlx->player->x / 32 - 7;
		y = 0;
		tmp = j;
		while(tmp <= 0)
		{
			tmp++;
			y++;
		}
		while(j < mlx->player->x / 32 + 7)
		{
			if (mlx->map->map[i][j] && mlx->map->map[i][j] == '1')
				draw_wallmap(mlx, x, y, 0xffffffff, mlx->minimap->img);
			j++;
			y++;
		}
		if (i < get_map_len(mlx->map->path) - 1)
		{
			x++;
			i++;
		}
		else
			py++;
		
		draw_wallmap(mlx, px, py, 0xff00FF00, mlx->minimap->img);
	}
	my_put_image(mlx, &(t_xy ){10, 10}, &(t_wh){150, 150}, mlx->minimap->img, 1);
	mlx_destroy_image(mlx->mlx, mlx->minimap->img);
}
