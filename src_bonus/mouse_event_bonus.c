/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:46:12 by bapasqui          #+#    #+#             */
/*   Updated: 2024/08/18 22:17:03 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	mouse_hook(int button, void *param)
{
	t_mlx	*mlx;

	mlx = param;
	if (button == 1)
		mlx->player->keys->mouse_click = 1;
	return (0);
}

int	mouse_reset(int button, void *param)
{
	t_mlx	*mlx;

	mlx = param;
	(void)button;
	if (mlx->player->keys->mouse_click == 1)
		mlx->player->keys->mouse_click = 0;
	return (0);
}
