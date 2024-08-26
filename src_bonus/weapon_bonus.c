/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapt <bapt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:45:37 by qdeviann          #+#    #+#             */
/*   Updated: 2024/08/26 12:51:19 by bapt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <sys/time.h>

long int	actual_time(void)
{
	long int		time;
	struct timeval	current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
		ft_printf_fd(2, "Error: gettimeofday failed\n");
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	render_weapon(t_mlx *mlx, void *img_1, void *img_2, t_xy *pos)
{
	static long int	start_time = 0;
	long int		current_time;

	my_put_image(mlx, pos, &(t_wh){256, 256, 1}, img_1);
	if (mlx->player->keys->mouse_click == 1)
	{
		if (mlx->player->weapon == 1)
			fov_details(mlx);
		my_put_image(mlx, pos, &(t_wh){256, 256, 1}, img_2);
		current_time = actual_time();
		if (mlx->player->weapon == 2 && current_time - start_time >= 100)
		{
			system("cvlc --play-and-exit sounds/weapon_rifle.wav > \
				/dev/null 2>&1 &");
			my_put_image(mlx, pos, &(t_wh){256, 256, 1}, img_1);
			start_time = current_time;
		}
	}
}

void	weapon_bonus(t_mlx *mlx)
{
	if (mlx->player->weapon == 1)
		render_weapon(mlx, mlx->weapon->knife_0, mlx->weapon->knife_1,
			&(t_xy){WINDOW_HEIGHT - 256, WINDOW_WIDTH / 2});
	else if (mlx->player->weapon == 0)
		render_weapon(mlx, mlx->weapon->pistol_0, mlx->weapon->pistol_1,
			&(t_xy){WINDOW_HEIGHT - 256, (WINDOW_WIDTH - 256) / 2});
	else if (mlx->player->weapon == 2)
		render_weapon(mlx, mlx->weapon->rifle_0, mlx->weapon->rifle_1,
			&(t_xy){WINDOW_HEIGHT - 256, (WINDOW_WIDTH - 256) / 2});
	my_put_image(mlx, &(t_xy){(WINDOW_HEIGHT - 64) / 2, (WINDOW_WIDTH - 64)
		/ 2}, &(t_wh){64, 64, 1}, mlx->weapon->crosshair);
}
