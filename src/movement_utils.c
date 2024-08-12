/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 22:44:23 by bapasqui          #+#    #+#             */
/*   Updated: 2024/08/12 16:10:39 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	handle_collision(t_mlx *mlx, int neg)
{
	int	x;
	int	y;

	x = mlx->player->x;
	y = mlx->player->y;
	if (neg)
	{
		x -= (mlx->player->delta_x * 5);
		y -= (mlx->player->delta_y * 5);
	}
	else
	{
		x += (mlx->player->delta_x * 5);
		y += (mlx->player->delta_y * 5);
	}
	if (mlx->map->map[y / TILL_S][x / TILL_S] == '1')
		return (0);
	return (1);
}

void	rotation_direction(char *direction, t_mlx *mlx)
{
	if (!ft_strncmp(direction, "left", 4))
	{
		mlx->player->angle -= 0.1;
		if (mlx->player->angle < 0)
			mlx->player->angle += 2 * PI;
	}
	else if (!ft_strncmp(direction, "right", 5))
	{
		mlx->player->angle += 0.1;
		if (mlx->player->angle > 2 * PI)
			mlx->player->angle -= 2 * PI;
	}
	mlx->player->delta_x = cos(mlx->player->angle) * mlx->player->speed;
	mlx->player->delta_y = sin(mlx->player->angle) * mlx->player->speed;
}

void	basic_direction(char *key, t_mlx *mlx)
{
	mlx->player->delta_x = cos(mlx->player->angle) * mlx->player->speed;
	mlx->player->delta_y = sin(mlx->player->angle) * mlx->player->speed;
	if (!ft_strncmp(key, "w", 1))
	{
		if (handle_collision(mlx, 0))
		{
			mlx->player->x += mlx->player->delta_x;
			mlx->player->y += mlx->player->delta_y;
		}
	}
	else if (!ft_strncmp(key, "s", 1))
	{
		if (handle_collision(mlx, 1))
		{
			mlx->player->x -= mlx->player->delta_x;
			mlx->player->y -= mlx->player->delta_y;
		}
	}
}

void	lr_direction(char *key, t_mlx *mlx)
{
	mlx->player->delta_x = cos(mlx->player->angle - PI / 2)
		* mlx->player->speed;
	mlx->player->delta_y = sin(mlx->player->angle - PI / 2)
		* mlx->player->speed;
	if (!ft_strncmp(key, "a", 1))
	{
		if (handle_collision(mlx, 1))
		{
			mlx->player->x -= mlx->player->delta_x;
			mlx->player->y -= mlx->player->delta_y;
		}
	}
	else if (!ft_strncmp(key, "d", 1))
	{
		if (handle_collision(mlx, 0))
		{
			mlx->player->x += mlx->player->delta_x;
			mlx->player->y += mlx->player->delta_y;
		}
	}
}
