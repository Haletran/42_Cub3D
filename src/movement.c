/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapt <bapt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:24:46 by bapasqui          #+#    #+#             */
/*   Updated: 2024/08/24 15:19:54 by bapt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	rotate_player(void *param)
{
	t_mlx	*mlx;

	mlx = param;
	if (mlx->player->keys->left == 1)
		rotation_direction("left", mlx);
	if (mlx->player->keys->right == 1)
		rotation_direction("right", mlx);
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
	if (key == SHIFT_KEY)
		mlx->player->keys->shift = 1;
	return (0);
}
