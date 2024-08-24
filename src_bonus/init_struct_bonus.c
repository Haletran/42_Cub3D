/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapt <bapt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 21:36:42 by bapasqui          #+#    #+#             */
/*   Updated: 2024/08/24 23:58:04 by bapt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	attrib_textures(t_mlx *mlx, t_img *img, char *path)
{
	img->img = mlx_png_file_to_image(mlx->mlx, path, &img->t_wid, &img->t_hei);
	if (!img->img)
		return (ft_error(MLX_SPRITE_ERROR));
	return (SUCCESS);
}

static int	attrib_sprites(t_mlx *mlx, void **img, char *path)
{
	int	width;
	int	height;

	width = 256;
	height = 256;
	(*img) = mlx_png_file_to_image(mlx->mlx, path, &width, &height);
	if (!img)
		return (ft_error(MLX_SPRITE_ERROR));
	return (SUCCESS);
}

int	init_textures(t_mlx **mlx)
{
	int	error;

	error = 0;
	(*mlx)->img_n = ft_calloc(1, sizeof(t_img));
	if (!(*mlx)->img_n)
		return (ft_error(MALLOC_ERROR));
	(*mlx)->img_s = ft_calloc(1, sizeof(t_img));
	if (!(*mlx)->img_s)
		return (ft_error(MALLOC_ERROR));
	(*mlx)->img_e = ft_calloc(1, sizeof(t_img));
	if (!(*mlx)->img_e)
		return (ft_error(MALLOC_ERROR));
	(*mlx)->img_w = ft_calloc(1, sizeof(t_img));
	if (!(*mlx)->img_w)
		return (ft_error(MALLOC_ERROR));
	error += attrib_textures((*mlx), (*mlx)->img_n, (*mlx)->map->data_map->no);
	error += attrib_textures((*mlx), (*mlx)->img_s, (*mlx)->map->data_map->so);
	error += attrib_textures((*mlx), (*mlx)->img_e, (*mlx)->map->data_map->ea);
	error += attrib_textures((*mlx), (*mlx)->img_w, (*mlx)->map->data_map->we);
	if (error >= 1)
		return (ERROR);
	return (SUCCESS);
}

int	init_images(t_mlx **mlx)
{
	int	error;

	error = 0;
	if (init_textures(mlx) == ERROR)
		return (ERROR);
	(*mlx)->minimap = ft_calloc(1, sizeof(t_img));
	(*mlx)->weapon = ft_calloc(1, sizeof(t_weapon));
	(*mlx)->weapon->width = 256;
	(*mlx)->weapon->height = 256;
	error += attrib_sprites((*mlx), &(*mlx)->weapon->knife_0,
			"images/knife_1.png");
	error += attrib_sprites((*mlx), &(*mlx)->weapon->knife_1,
			"images/knife_3.png");
	error += attrib_sprites((*mlx), &(*mlx)->weapon->crosshair,
			"images/crosshair.png");
	error += attrib_sprites((*mlx), &(*mlx)->weapon->pistol_0,
			"images/pistol_0.png");
	error += attrib_sprites((*mlx), &(*mlx)->weapon->pistol_1,
			"images/pistol_1.png");
	(*mlx)->player->keys->mouse_click = 0;
	if (error >= 1)
		return (ERROR);
	return (SUCCESS);
}

int	init_player(t_mlx **mlx)
{
	(*mlx)->player->x = 0;
	(*mlx)->player->y = 0;
	(*mlx)->player->angle = 0;
	(*mlx)->player->minimap = 0;
	(*mlx)->player->debug = 0;
	(*mlx)->player->eye_h = 0;
	(*mlx)->player->save = 0;
	(*mlx)->player->dir = 0;
	(*mlx)->player->speed = 0;
	(*mlx)->flood_error = false;
	(*mlx)->player->delta_x = cos((*mlx)->player->angle) * 5;
	(*mlx)->player->delta_y = sin((*mlx)->player->angle) * 5;
	(*mlx)->map->file_lenght = get_map_len((*mlx)->map->path);
	(*mlx)->player->keys = ft_calloc(1, sizeof(t_key));
	if (!(*mlx)->player->keys)
		return (ft_error(MALLOC_ERROR));
	(*mlx)->player->keys->w = 0;
	(*mlx)->player->keys->a = 0;
	(*mlx)->player->keys->s = 0;
	(*mlx)->player->keys->d = 0;
	(*mlx)->player->keys->left = 0;
	(*mlx)->player->keys->right = 0;
	(*mlx)->player->keys->shift = 0;
	(*mlx)->player->speed = PLAYER_SPEED;
	return (SUCCESS);
}
