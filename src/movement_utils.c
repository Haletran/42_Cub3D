/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 22:44:23 by bapasqui          #+#    #+#             */
/*   Updated: 2024/05/29 22:51:34 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotation_direction(char *direction, t_mlx *mlx)
{
	if (!ft_strncmp(direction, "left", 4))
	{
		mlx->player->angle -= 0.2;
		if (mlx->player->angle < 0)
			mlx->player->angle += 2 * PI;
		mlx->player->delta_x = cos(mlx->player->angle) * 5;
		mlx->player->delta_y = sin(mlx->player->angle) * 5;
	}
	else if (!ft_strncmp(direction, "right", 5))
	{
		mlx->player->angle += 0.2;
		if (mlx->player->angle > 0)
			mlx->player->angle -= 2 * PI;
		mlx->player->delta_x = cos(mlx->player->angle) * 5;
		mlx->player->delta_y = sin(mlx->player->angle) * 5;
	}
}

void	basic_direction(char *key, t_mlx *mlx)
{
	if (!ft_strncmp(key, "w", 1))
	{
		mlx->player->delta_x = cos(mlx->player->angle) * 5;
		mlx->player->delta_y = sin(mlx->player->angle) * 5;
		mlx->player->x += mlx->player->delta_x;
		mlx->player->y += mlx->player->delta_y;
	}
	else if (!ft_strncmp(key, "s", 1))
	{
		mlx->player->delta_x = cos(mlx->player->angle) * 5;
		mlx->player->delta_y = sin(mlx->player->angle) * 5;
		mlx->player->x -= mlx->player->delta_x;
		mlx->player->y -= mlx->player->delta_y;
	}
}
