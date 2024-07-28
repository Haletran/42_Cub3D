/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapt <bapt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:37:15 by bapasqui          #+#    #+#             */
/*   Updated: 2024/07/28 03:05:31 by bapt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_textures(t_mlx **mlx)
{
	(*mlx)->img_n = ft_calloc(1, sizeof(t_img));
	(*mlx)->img_s = ft_calloc(1, sizeof(t_img));
	(*mlx)->img_e = ft_calloc(1, sizeof(t_img));
	(*mlx)->img_w = ft_calloc(1, sizeof(t_img));
	(*mlx)->img_n->img = mlx_png_file_to_image((*mlx)->mlx,
			(*mlx)->map->data_map->no, &(*mlx)->img_n->t_wid,
			&(*mlx)->img_n->t_hei);
	(*mlx)->img_s->img = mlx_png_file_to_image((*mlx)->mlx,
			(*mlx)->map->data_map->so, &(*mlx)->img_s->t_wid,
			&(*mlx)->img_s->t_hei);
	(*mlx)->img_e->img = mlx_png_file_to_image((*mlx)->mlx,
			(*mlx)->map->data_map->ea, &(*mlx)->img_e->t_wid,
			&(*mlx)->img_e->t_hei);
	(*mlx)->img_w->img = mlx_png_file_to_image((*mlx)->mlx,
			(*mlx)->map->data_map->we, &(*mlx)->img_w->t_wid,
			&(*mlx)->img_w->t_hei);
}

int	init_images(t_mlx **mlx)
{
	int	img_width;
	int	img_height;

	img_width = 32;
	img_height = 32;
	(*mlx)->wall = mlx_png_file_to_image((*mlx)->mlx, "images/bar.png",
			&img_width, &img_height);
	init_textures(mlx);
	return (SUCCESS);
}

static int	init_values(t_mlx **mlx, char **str)
{
	(*mlx)->map->path = ft_strdup(str[1]);
	if (ft_strncmp((*mlx)->map->path + ft_strlen((*mlx)->map->path) - 4, ".cub",
			4))
		return (ft_error(NOT_CUB_ERROR));
	(*mlx)->player->x = 40;
	(*mlx)->player->y = 40;
	(*mlx)->player->angle = 0;
	(*mlx)->player->minimap = 0;
	(*mlx)->player->delta_x = cos((*mlx)->player->angle) * 5;
	(*mlx)->player->delta_y = sin((*mlx)->player->angle) * 5;
	(*mlx)->map->file_lenght = get_map_len((*mlx)->map->path);
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
	if (init_map((*mlx)) != SUCCESS)
		return (ERROR);
    if (check_map_validity((*mlx), (*mlx)->map->map) == ERROR)
        return (ERROR);
    (*mlx)->map->data_map->floor_c = convert_rgb_to_hex((*mlx)->map->data_map->floor_char);
	(*mlx)->map->data_map->sky_c = convert_rgb_to_hex((*mlx)->map->data_map->sky_char);
	(*mlx)->map->data_map->floor_char = free_char((*mlx)->map->data_map->floor_char);
	(*mlx)->map->data_map->sky_char = free_char((*mlx)->map->data_map->sky_char);
	init_images(mlx);
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
