/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:13:14 by bapasqui          #+#    #+#             */
/*   Updated: 2024/05/03 19:01:27 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_hook(int key, void *param)
{
	t_mlx	*mlx;

	mlx = param;
	if (key == KEY_ESC)
		mlx_loop_end(mlx->mlx);
	if ((key == KEY_W || key == UP_ARROW) && mlx->map->map[(int)(mlx->player->y + mlx->player->delta_y) / 33][(int)(mlx->player->x + mlx->player->delta_x) / 33] != '1')
    {
        mlx->player->x += mlx->player->delta_x;
        mlx->player->y += mlx->player->delta_y;
    }
	if ((key == KEY_A || key == LEFT_ARROW))
    {
        mlx->player->angle -= 0.2;
        if (mlx->player->angle < 0)
            mlx->player->angle += 2 * PI;
        mlx->player->delta_x = cos(mlx->player->angle) * 5;
        mlx->player->delta_y = sin(mlx->player->angle) * 5;
    }
    if ((key == KEY_S || key == DOWN_ARROW) && mlx->map->map[(int)(mlx->player->y - mlx->player->delta_y) / 33][(int)(mlx->player->x - mlx->player->delta_x) / 33] != '1')
    {
        mlx->player->x -= mlx->player->delta_x;
        mlx->player->y -= mlx->player->delta_y;
    }
	if ((key == KEY_D || key == RIGHT_ARROW))
    {
        mlx->player->angle += 0.2;
        if (mlx->player->angle > 2 * PI)
            mlx->player->angle -= 2 * PI;
        mlx->player->delta_x = cos(mlx->player->angle) * 5;
        mlx->player->delta_y = sin(mlx->player->angle) * 5;
    }
    mlx_clear_window(mlx->mlx, mlx->win);
    rotate_player(mlx);
    draw_map(mlx);
    render_player(mlx);
    //draw_rays(mlx);
	return (0);
}

int	window_hook(int event, void *param)
{
	t_mlx *mlx;

	mlx = param;
	if (event == 0)
		mlx_loop_end(mlx->mlx);
	return (0);
}