/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:24:46 by bapasqui          #+#    #+#             */
/*   Updated: 2024/06/24 16:10:51 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_hook(int key, void *param)
{
	t_mlx	*mlx;

	mlx = param;
	if (key == 'w')
	{
		if (mlx->map->map[(int)(mlx->player->y + mlx->player->delta_y)
			/ 32][(int)(mlx->player->x + mlx->player->delta_x) / 32] != '1')
			basic_direction("w", mlx);
	}
	if (key == 's')
	{
		if (mlx->map->map[(int)(mlx->player->y + mlx->player->delta_y)
			/ 32][(int)(mlx->player->x + mlx->player->delta_x) / 32] != '1')
			basic_direction("s", mlx);
	}
	if (key == LEFT_ARROW)
		rotation_direction("left", mlx);
	if (key == RIGHT_ARROW)
		rotation_direction("right", mlx);
	if (key == 'a' && mlx->map->map[(int)(mlx->player->y - mlx->player->delta_y)
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
	if (key == 'd' && mlx->map->map[(int)(mlx->player->y - mlx->player->delta_y)
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
	if (key == 'm')
	{
		if (mlx->map->print == 0)
			mlx->map->print = 1;
		else
			mlx->map->print = 0;
	}
	fov_details(mlx);
	return (0);
}
