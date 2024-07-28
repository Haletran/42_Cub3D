/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapt <bapt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:24:46 by bapasqui          #+#    #+#             */
/*   Updated: 2024/07/28 02:42:51 by bapt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_hook(int key, void *param)
{
	t_mlx	*mlx;

	mlx = param;
	if (key == ECHAP_KEY)
	{
		mlx->player->key = ECHAP;
		exit(1);
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
	fov_details(mlx);
	return (0);
}
