/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:46:12 by bapasqui          #+#    #+#             */
/*   Updated: 2024/08/25 16:26:41 by bapasqui         ###   ########.fr       */
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
	{
		mlx->player->keys->mouse_click = 0;
		if (mlx->player->weapon == 0)
			system("cvlc --play-and-exit sounds/weapon_pistol.wav > \
				/dev/null 2>&1 &");
		else if (mlx->player->weapon == 1)
			system("cvlc --play-and-exit sounds/weapon_knife.wav > \
				/dev/null 2>&1 &");
	}
	return (0);
}

int	mouse_wheel_hook(int button, void *param)
{
	t_mlx	*mlx;

	mlx = param;
	if (button == 1)
		mlx->player->weapon = (mlx->player->weapon + 1) % 3;
	else if (button == 2)
		mlx->player->weapon = (mlx->player->weapon - 1 + 3) % 3;
	return (0);
}
