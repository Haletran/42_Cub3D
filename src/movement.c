/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:24:46 by bapasqui          #+#    #+#             */
/*   Updated: 2024/08/11 21:29:18 by bapasqui         ###   ########.fr       */
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

int	move_player(void *param)
{
	t_mlx	*mlx;

	mlx = param;
	if (mlx->player->keys->w)
		basic_direction("w", mlx);
	if (mlx->player->keys->s)
		basic_direction("s", mlx);
	if (mlx->player->keys->d)
		lr_direction("d", mlx);
	if (mlx->player->keys->a)
		lr_direction("a", mlx);
	if (mlx->player->keys->left)
		rotation_direction("left", mlx);
	if (mlx->player->keys->right)
		rotation_direction("right", mlx);
	if (mlx->player->keys->shift)
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
	fov_details(mlx);
	move_player(mlx);
	return (0);
}
