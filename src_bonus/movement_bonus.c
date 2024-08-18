/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:24:46 by bapasqui          #+#    #+#             */
/*   Updated: 2024/08/18 23:40:30 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	activate_minimap(t_mlx *mlx)
{
	if (mlx->player->minimap == 0)
		mlx->player->minimap = 1;
	else
		mlx->player->minimap = 0;
}

void	activate_fps(t_mlx *mlx)
{
	if (mlx->player->fps_counter == 0)
		mlx->player->fps_counter = 1;
	else
		mlx->player->fps_counter = 0;
}

int	rotate_player(void *param)
{
	t_mlx	*mlx;
	int		x;
	int		y;

	x = 0;
	y = 0;
	mlx = param;
	mlx_mouse_get_pos(mlx->mlx, &x, &y);
	if (x > WINDOW_WIDTH / 2)
		rotation_direction("right", mlx);
	if (x < WINDOW_WIDTH / 2)
		rotation_direction("left", mlx);
	mlx_mouse_move(mlx->mlx, mlx->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	return (SUCCESS);
}

int	move_player(void *param)
{
	t_mlx	*mlx;

	mlx = param;
	if (mlx->player->keys->w == 1)
		basic_direction("w", mlx);
	if (mlx->player->keys->s == 1)
		basic_direction("s", mlx);
	if (mlx->player->keys->d == 1)
		lr_direction("d", mlx);
	if (mlx->player->keys->a == 1)
		lr_direction("a", mlx);
	if (mlx->player->keys->shift == 1)
		mlx->player->speed = PLAYER_SPEED * 2;
	return (0);
}

int	keydown_keys(int key, void *params)
{
	t_mlx	*mlx;

	mlx = params;
	if (key == ECHAP_KEY)
		mlx_loop_end(mlx->mlx);
	if (key == W_KEY)
		mlx->player->keys->w = 1;
	if (key == S_KEY)
		mlx->player->keys->s = 1;
	if (key == LEFT_ARROW)
		mlx->player->keys->left = 1;
	if (key == RIGHT_ARROW)
		mlx->player->keys->right = 1;
	if (key == D_KEY)
		mlx->player->keys->d = 1;
	if (key == A_KEY)
		mlx->player->keys->a = 1;
	if (key == M_KEY)
		activate_minimap(mlx);
	if (key == SHIFT_KEY)
		mlx->player->keys->shift = 1;
	if (key == F_KEY)
		activate_fps(mlx);
	return (0);
}
