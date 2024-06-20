/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:37:15 by bapasqui          #+#    #+#             */
/*   Updated: 2024/06/05 23:07:59 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_textures(t_mlx **mlx)
{
	(*mlx)->img_n = ft_calloc(1, sizeof(t_img));
	(*mlx)->img_n->img = mlx_xpm_file_to_image((*mlx)->mlx, "textures/1.xpm", &(*mlx)->size, &(*mlx)->size);
	(*mlx)->img_n->pix_map = (int *)mlx_get_data_addr((*mlx)->img_n->img ,&(*mlx)->img_n->bpp ,&(*mlx)->img_n->size_line, &(*mlx)->img_n->endian);
}

int	init_images(t_mlx **mlx)
{
	int		img_width;
	int		img_height;

	img_width = 32;
	img_height = 32;
	(*mlx)->wall = mlx_xpm_file_to_image((*mlx)->mlx, "images/floor.xpm", &img_width, &img_height);
	init_textures(mlx);
	return (SUCCESS);
}

int init(t_mlx **mlx, char **str)
{
	(*mlx)->map = ft_calloc(1, sizeof(t_map));
	(*mlx)->ray = ft_calloc(1, sizeof(t_ray));
	if (!(*mlx)->ray || !(*mlx)->map)
		return (ft_error(MALLOC_ERROR));
	(*mlx)->map->path = ft_strdup(str[1]);
	(*mlx)->player = ft_calloc(1, sizeof(t_player));
	if (!(*mlx)->player)
		return (ft_error(MALLOC_ERROR));
	if (init_images(mlx) != SUCCESS)
		return (ERROR);
	if (ft_strncmp((*mlx)->map->path + ft_strlen((*mlx)->map->path) - 4, ".cub", 4))
		return (ft_error(NOT_CUB));
	(*mlx)->player->x = 40;
	(*mlx)->player->y = 40;
	(*mlx)->player->angle = 0;
	(*mlx)->player->delta_x = cos((*mlx)->player->angle) * 5;
	(*mlx)->player->delta_y = sin((*mlx)->player->angle) * 5;
	(*mlx)->map->lenght = get_map_len((*mlx)->map->path);
	if ((*mlx)->map->lenght <= 0)
		return (ft_error(NOTHING));
	if (init_map((*mlx)) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}
