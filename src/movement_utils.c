/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapt <bapt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 22:44:23 by bapasqui          #+#    #+#             */
/*   Updated: 2024/07/28 02:42:49 by bapt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int handle_collision(t_mlx *mlx)
{
	int x;
	int y;

	x = (int)(mlx->player->x / 32);
	y = (int)(mlx->player->y / 32);
	if (mlx->map->map[y][x + 1] == '1')
		return (1);
	return (0);
}


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
		if (mlx->player->angle > 2 * PI)
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

void lr_direction(char *key, t_mlx *mlx)
{
	if (!ft_strncmp(key, "a", 1))
	{
		mlx->player->delta_x = cos(mlx->player->angle - PI / 2) * 5;
		mlx->player->delta_y = sin(mlx->player->angle - PI / 2) * 5;
		mlx->player->x -= mlx->player->delta_x;
		mlx->player->y -= mlx->player->delta_y;
	}
	else if (!ft_strncmp(key, "d", 1))
	{
		mlx->player->delta_x = cos(mlx->player->angle - PI / 2) * 5;
		mlx->player->delta_y = sin(mlx->player->angle - PI / 2) * 5;
		mlx->player->x += mlx->player->delta_x;
		mlx->player->y += mlx->player->delta_y;
	}
}
