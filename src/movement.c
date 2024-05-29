/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:24:46 by bapasqui          #+#    #+#             */
/*   Updated: 2024/05/29 22:56:31 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_fov(t_mlx *mlx)
{
	int	i;

	i = 0;
	mlx->player->angle -= 0.0034 * FOV / 2;
	while (i < FOV)
	{
		mlx->player->angle += 0.0034;
		if (mlx->player->angle < 2 * PI)
			mlx->player->angle -= 2 * PI;
		mlx->player->delta_x = cos(mlx->player->angle) * 5;
		mlx->player->delta_y = sin(mlx->player->angle) * 5;
		rotate_line(mlx);
		i++;
	}
	mlx->player->angle -= 0.0034 * FOV / 2;
}

void	rotate_line(t_mlx *mlx)
{
	float	i;
	double	x;
	double	y;

	i = 0; // Ecart des rayons
	while (i < RAYS_SIZE)
	{
		x = mlx->player->x + i * cos(mlx->player->angle);
		y = mlx->player->y + i * sin(mlx->player->angle);
		if (mlx->map->map[(int)y / 32][(int)x / 32] == '1')
			break ;
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0xFFE8FF00);
		i += 0.2;
	}
}

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
			mlx->player->x += mlx->player->delta_x;
			mlx->player->y += mlx->player->delta_y;
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
			mlx->player->x -= mlx->player->delta_x;
			mlx->player->y -= mlx->player->delta_y;
		}
		else
		{
			mlx->player->delta_x = cos(mlx->player->angle + PI / 2) * 5;
			mlx->player->delta_y = sin(mlx->player->angle + PI / 2) * 5;
			mlx->player->x += mlx->player->delta_x;
			mlx->player->y += mlx->player->delta_y;
		}
	}
	mlx_clear_window(mlx->mlx, mlx->win);
	draw_map(mlx);
	rotate_fov(mlx);
	return (0);
}
