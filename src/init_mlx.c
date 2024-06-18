/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:37:15 by bapasqui          #+#    #+#             */
/*   Updated: 2024/06/18 23:22:24 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_images(t_mlx **mlx)
{
	int	img_width;
	int	img_height;

	img_width = 32;
	img_height = 32;
	(*mlx)->floor = mlx_xpm_file_to_image((*mlx)->mlx, "images/floor.xpm",
			&img_width, &img_height);
	(*mlx)->wall = mlx_xpm_file_to_image((*mlx)->mlx, "images/wall.xpm",
			&img_width, &img_height);
	return (SUCCESS);
}

static int	init_values(t_mlx **mlx, char **str)
{
    (*mlx)->map->path = ft_strdup(str[1]);
    (*mlx)->player->x = 40;
    (*mlx)->player->y = 40;
    (*mlx)->player->angle = 0;
    (*mlx)->player->delta_x = cos((*mlx)->player->angle) * 5;
    (*mlx)->player->delta_y = sin((*mlx)->player->angle) * 5;
    (*mlx)->map->file_lenght = get_map_len((*mlx)->map->path);
    if ((*mlx)->map->file_lenght <= 0)
        return (ft_error(NOTHING));
    return (SUCCESS);
}

static int	check_file_and_init(t_mlx **mlx)
{
    if (read_file((*mlx)) != SUCCESS)
        return (ERROR);
    if (attribute_data_map((*mlx)) != SUCCESS)
        return (ERROR);
    if (init_map((*mlx)) != SUCCESS)
        return (ERROR);
    (*mlx)->map->data_map->floor_c = convert_rgb_to_hex((*mlx)->map->data_map->floor_char);
    (*mlx)->map->data_map->sky_c = convert_rgb_to_hex((*mlx)->map->data_map->sky_char);
    (*mlx)->map->data_map->floor_char = free_char((*mlx)->map->data_map->floor_char);
    (*mlx)->map->data_map->sky_char = free_char((*mlx)->map->data_map->sky_char);
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
    if (ft_strncmp((*mlx)->map->path + ft_strlen((*mlx)->map->path) - 4, ".cub", 4))
        return (ft_error(NOT_CUB));
    if (check_file_and_init(mlx) != SUCCESS)
        return (ERROR);
    return (SUCCESS);
}
