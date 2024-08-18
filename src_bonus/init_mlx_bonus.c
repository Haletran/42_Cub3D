/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:37:15 by bapasqui          #+#    #+#             */
/*   Updated: 2024/08/18 22:31:47 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_file(char *filename)
{
	size_t	len;

	len = ft_strlen(filename) - 4;
	if (len < 4)
		return (0);
	if (open(filename, O_RDONLY) < 0)
		return (ERROR);
	if (ft_strstr(filename, ".cub") && !ft_strcmp(filename + len, ".cub"))
		return (SUCCESS);
	return (ERROR);
}

static int	init_values(t_mlx **mlx, char **str)
{
	if (check_file(str[1]) == ERROR)
		return (ft_error(FILE_ERROR));
	(*mlx)->map->path = ft_strdup(str[1]);
	(*mlx)->flood_error = false;
	(*mlx)->player_check = 0;
	(*mlx)->map->file_lenght = get_map_len((*mlx)->map->path);
	if ((*mlx)->map->file_lenght >= 40)
		return (ft_error(FILE_ERROR));
	if (init_player(mlx))
		return (ERROR);
	if ((*mlx)->map->file_lenght <= 0)
		return (ft_error(NOTHING_ERROR));
	return (SUCCESS);
}

static int	check_file_and_init(t_mlx **mlx)
{
	if (read_file((*mlx)) != SUCCESS)
		return (ERROR);
	if (attribute_data_map((*mlx)) != SUCCESS)
		return (ERROR);
	(*mlx)->map->start_map = (*mlx)->counter;
	if (init_map(mlx) != SUCCESS)
		return (ERROR);
	if (check_map_validity((*mlx), (*mlx)->map->map) == ERROR)
		return (ft_error(MAP_ERROR));
	free_char((*mlx)->map->data_map->floor_char);
	(*mlx)->map->data_map->floor_char = NULL;
	free_char((*mlx)->map->data_map->sky_char);
	(*mlx)->map->data_map->sky_char = NULL;
	if (init_images(mlx) == ERROR)
		return (ERROR);
	(*mlx)->map->file = ft_copy_tab((*mlx)->map->map,
			get_width((*mlx)->map->map));
	flood_fill((*mlx)->map->file, (*mlx), (int)(*mlx)->player->x / TILL_S,
		(int)(*mlx)->player->y / TILL_S);
	if ((*mlx)->flood_error == true || (*mlx)->player_check > 1)
		return (ft_error(MAP_ERROR));
	return (SUCCESS);
}

int	init(t_mlx **mlx, char **str)
{
	(*mlx)->map = ft_calloc(1, sizeof(t_map));
	(*mlx)->ray = ft_calloc(1, sizeof(t_ray));
	(*mlx)->map->data_map = ft_calloc(1, sizeof(t_data_map));
	if (!(*mlx)->ray || !(*mlx)->map || !(*mlx)->map->data_map)
		return (ft_error(MALLOC_ERROR));
	(*mlx)->player = ft_calloc(1, sizeof(t_player));
	if (!(*mlx)->player)
		return (ft_error(MALLOC_ERROR));
	if (init_values(mlx, str) != SUCCESS)
		return (ERROR);
	if (check_file_and_init(mlx) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}