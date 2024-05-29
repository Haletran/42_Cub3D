/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:24:46 by bapasqui          #+#    #+#             */
/*   Updated: 2024/05/29 20:28:55 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_fov(t_mlx *mlx)
{
	int i;

	i = 0;
	mlx->player->angle -= 0.0034 * 150;
	while(i < 300)
	{
		mlx->player->angle += 0.0034;
		if (mlx->player->angle < 2 * PI)
			mlx->player->angle -= 2 * PI;
		mlx->player->delta_x = cos(mlx->player->angle) * 5;
		mlx->player->delta_y = sin(mlx->player->angle) * 5;
		rotate_line(mlx);
		i++;
	}
	mlx->player->angle -= 0.0034 * 150;
}

void	rotate_line(t_mlx *mlx)
{
	int		steps;
	float		i;
	double	x;
	double	y;
	double	m;

	steps = 80;
	i = 0;
	y = 0;
	x = 0;
	m = mlx->player->delta_y / mlx->player->delta_x;
	while (i < steps)
	{
		x = mlx->player->x + i * mlx->player->delta_x;
		y = mlx->player->y + m * i * mlx->player->delta_x;
		if (mlx->map->map[(int)y / 32][(int)x / 32] == '1')
			break;
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0xFFE8FF00);
		i+= 0.1;

	}
}

int	key_hook(int key, void *param)
{
	t_mlx	*mlx;

	mlx = param;
	if ((key == 'w') && mlx->map->map[(int)(mlx->player->y
			+ mlx->player->delta_y) / 32][(int)(mlx->player->x
			+ mlx->player->delta_x) / 32] != '1')
	{
		mlx->player->delta_x = cos(mlx->player->angle) * 5;
		mlx->player->delta_y = sin(mlx->player->angle) * 5;
		mlx->player->x += mlx->player->delta_x;
		mlx->player->y += mlx->player->delta_y;
	}
	if (key == LEFT_ARROW)
	{
		mlx->player->angle -= 0.2;
		if (mlx->player->angle < 0)
			mlx->player->angle += 2 * PI;
		mlx->player->delta_x = cos(mlx->player->angle) * 5;
		mlx->player->delta_y = sin(mlx->player->angle) * 5;
	}
	if ((key == 's')
		&& mlx->map->map[(int)(mlx->player->y - mlx->player->delta_y)
		/ 32][(int)(mlx->player->x - mlx->player->delta_x) / 32] != '1')
	{
		mlx->player->delta_x = cos(mlx->player->angle) * 5;
		mlx->player->delta_y = sin(mlx->player->angle) * 5;
		mlx->player->x -= mlx->player->delta_x;
		mlx->player->y -= mlx->player->delta_y;
	}
	if (key == RIGHT_ARROW)
	{
		mlx->player->angle += 0.2;
		if (mlx->player->angle > 0)
			mlx->player->angle -= 2 * PI;
		mlx->player->delta_x = cos(mlx->player->angle) * 5;
		mlx->player->delta_y = sin(mlx->player->angle) * 5;
	}
	if (key == 'a')
	{	
		if (mlx->player->angle > PI/2 && mlx->player->angle < 3 * PI / 2)
		{	
			mlx->player->delta_x = cos(mlx->player->angle + PI/2) * 5;
			mlx->player->delta_y = sin(mlx->player->angle + PI/2) * 5;
			mlx->player->x += mlx->player->delta_x;
			mlx->player->y += mlx->player->delta_y;
		}
		else
		{
			mlx->player->delta_x = cos(mlx->player->angle + PI/2) * 5;
			mlx->player->delta_y = sin(mlx->player->angle + PI/2) * 5;
			mlx->player->x -= mlx->player->delta_x;
			mlx->player->y -= mlx->player->delta_y;
		}
		
	}
	if (key == 'd')
	{		
		if (mlx->player->angle > PI/2 && mlx->player->angle < 3 * PI / 2)
		{	
			mlx->player->delta_x = cos(mlx->player->angle + PI/2) * 5;
			mlx->player->delta_y = sin(mlx->player->angle + PI/2) * 5;
			mlx->player->x -= mlx->player->delta_x;
			mlx->player->y -= mlx->player->delta_y;
		}
		else
		{
			mlx->player->delta_x = cos( mlx->player->angle + PI/2) * 5;
			mlx->player->delta_y = sin(mlx->player->angle + PI/2) * 5;
			mlx->player->x += mlx->player->delta_x;
			mlx->player->y += mlx->player->delta_y;
		}
	}

    draw_map(mlx);
	rotate_fov(mlx);
	return (0);
}
