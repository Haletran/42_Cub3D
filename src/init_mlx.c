/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:37:15 by bapasqui          #+#    #+#             */
/*   Updated: 2024/05/23 20:26:04 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int init_images(t_mlx **mlx)
{
	int	img_width;
	int	img_height;

	img_width = 32;
	img_height = 32;
	(*mlx)->floor = mlx_xpm_file_to_image((*mlx)->mlx, "images/floor.xpm", &img_width,
			&img_height);
	(*mlx)->wall = mlx_xpm_file_to_image((*mlx)->mlx, "images/wall.xpm", &img_width,
			&img_height);
	return (SUCCESS);
}

t_mlx	*init(t_mlx *mlx, char **str)
{
	mlx->map = ft_calloc(1, sizeof(t_map));
	mlx->ray = ft_calloc(1, sizeof(t_ray));
	mlx->error = ft_calloc(1, sizeof(t_message));
	if (!mlx->ray || !mlx->map || !mlx->error)
		return (NULL);
	mlx->map->path = ft_strdup(str[1]);
	mlx->player = ft_calloc(1, sizeof(t_player));
	if (!mlx->player)
		return (NULL);
	if (init_images(&mlx) == ERROR)
		return (NULL);
	mlx->player->x = 40;
	mlx->player->y = 40;
	mlx->player->angle = 0;
	mlx->player->delta_x = cos(mlx->player->angle) * 5;
	mlx->player->delta_y = sin(mlx->player->angle) * 5;
	if (open(mlx->map->path, O_RDONLY) == -1)
		return (NULL);
	mlx->map->lenght = get_map_len(mlx->map->path);
	init_map(mlx);
	return (mlx);
}
