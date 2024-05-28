/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:24:46 by bapasqui          #+#    #+#             */
/*   Updated: 2024/05/23 16:11:58 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_line(t_mlx *mlx)
{
	int		steps;
	int		i;
	double	x;
	double	y;
	double	m;

	steps = 20;
	i = 0;
	y = 0;
	x = 0;
	m = mlx->player->delta_y / mlx->player->delta_x;
	while (i < steps + 50)
	{
		x = mlx->player->x + i * mlx->player->delta_x / steps;
		y = mlx->player->y + m * i * mlx->player->delta_x / steps;
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0xFFE8FF00);
		i++;
	}
}

int	key_hook(int key, void *param)
{
	t_mlx	*mlx;

	mlx = param;
	if ((key == 'w' || key == UP_ARROW) && mlx->map->map[(int)(mlx->player->y
			+ mlx->player->delta_y) / 32][(int)(mlx->player->x
			+ mlx->player->delta_x) / 32] != '1')
	{
		mlx->player->x += mlx->player->delta_x;
		mlx->player->y += mlx->player->delta_y;
	}
	if ((key == 'a' || key == LEFT_ARROW))
	{
		mlx->player->angle -= 0.1;
		if (mlx->player->angle < 0)
			mlx->player->angle += 2 * PI;
		mlx->player->delta_x = cos(mlx->player->angle) * 5;
		mlx->player->delta_y = sin(mlx->player->angle) * 5;
	}
	if ((key == 's' || key == DOWN_ARROW)
		&& mlx->map->map[(int)(mlx->player->y - mlx->player->delta_y)
		/ 32][(int)(mlx->player->x - mlx->player->delta_x) / 32] != '1')
	{
		mlx->player->x -= mlx->player->delta_x;
		mlx->player->y -= mlx->player->delta_y;
	}
	if ((key == 'd' || key == RIGHT_ARROW))
	{
		mlx->player->angle += 0.1;
		if (mlx->player->angle > 2 * PI)
			mlx->player->angle -= 2 * PI;
		mlx->player->delta_x = cos(mlx->player->angle) * 5;
		mlx->player->delta_y = sin(mlx->player->angle) * 5;
	}
	mlx_clear_window(mlx->mlx, mlx->win);
    draw_map(mlx);
	rotate_line(mlx);
    render_player(mlx);
	return (0);
}
