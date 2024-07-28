/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:24:46 by bapasqui          #+#    #+#             */
/*   Updated: 2024/07/28 21:45:12 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void activate_minimap(t_mlx *mlx)
{
	if (mlx->player->minimap == 0)
		mlx->player->minimap = 1;
	else
		mlx->player->minimap = 0;
}

void others_actions(int key, t_mlx *mlx)
{
	if (key == H_KEY)
	{
		if (mlx->player->debug == 0)
			mlx->player->debug = 1;
		else
			mlx->player->debug = 0;
	}
}


int	key_hook(int key, void *param)
{
	t_mlx	*mlx;

	mlx = param;
	if (key == ECHAP_KEY)
	{
		mlx->player->key = ECHAP;
		mlx_loop_end(mlx->mlx);
	}
	if (key == W_KEY)
		basic_direction("w", mlx);
	if (key == S_KEY)
		basic_direction("s", mlx);
	if (key == LEFT_ARROW)
		rotation_direction("left", mlx);
	if (key == RIGHT_ARROW)
		rotation_direction("right", mlx);
	if (key == D_KEY)
		lr_direction("d", mlx);
	if (key == A_KEY)
		lr_direction("a", mlx);
	if (key == M_KEY)
		activate_minimap(mlx);
	others_actions(key, mlx);
	fov_details(mlx);
	return (0);
}
