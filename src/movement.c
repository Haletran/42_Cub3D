/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:24:46 by bapasqui          #+#    #+#             */
/*   Updated: 2024/07/08 22:30:27 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_hook(int key, void *param)
{
	t_mlx	*mlx;

	mlx = param;
	if (key == 41)
		exit(1);
	if (key == 26)
	{
		if (mlx->map->map[(int)(mlx->player->y + mlx->player->delta_y)
			/ 32][(int)(mlx->player->x + mlx->player->delta_x) / 32] != '1')
			basic_direction("w", mlx);
	}
	if (key == 22)
	{
		if (mlx->map->map[(int)(mlx->player->y + mlx->player->delta_y)
			/ 32][(int)(mlx->player->x + mlx->player->delta_x) / 32] != '1')
			basic_direction("s", mlx);
	}
	if (key == 80)
		rotation_direction("left", mlx);
	if (key == 79)
		rotation_direction("right", mlx);
	if (key == 4 && mlx->map->map[(int)(mlx->player->y - mlx->player->delta_y)
		/ 32][(int)(mlx->player->x - mlx->player->delta_x) / 32] != '1')
	{
		if (mlx->player->angle > PI / 2 && mlx->player->angle < 3 * PI / 2)
		{
			mlx->player->delta_x = cos(mlx->player->angle + PI / 2) * 5;
			mlx->player->delta_y = sin(mlx->player->angle + PI / 2) * 5;
			mlx->player->x -= mlx->player->delta_x;
			mlx->player->y -= mlx->player->delta_y;
		}
		else
		{
			mlx->player->delta_x = cos(mlx->player->angle + PI / 2) * 5;
			mlx->player->delta_y = sin(mlx->player->angle + PI / 2) * 5;
			mlx->player->x -= mlx->player->delta_x;
			mlx->player->y -= mlx->player->delta_y;
		}
	}
	if (key == 7 && mlx->map->map[(int)(mlx->player->y - mlx->player->delta_y)
		/ 32][(int)(mlx->player->x - mlx->player->delta_x) / 32] != '1')
	{
		if (mlx->player->angle > PI / 2 && mlx->player->angle < 3 * PI / 2)
		{
			mlx->player->delta_x = cos(mlx->player->angle + PI / 2) * 5;
			mlx->player->delta_y = sin(mlx->player->angle + PI / 2) * 5;
			mlx->player->x += mlx->player->delta_x;
			mlx->player->y += mlx->player->delta_y;
		}
		else
		{
			mlx->player->delta_x = cos(mlx->player->angle + PI / 2) * 5;
			mlx->player->delta_y = sin(mlx->player->angle + PI / 2) * 5;
			mlx->player->x += mlx->player->delta_x;
			mlx->player->y += mlx->player->delta_y;
		}
	}
	fov_details(mlx);
	return (0);
}
