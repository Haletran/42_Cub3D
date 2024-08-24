/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapt <bapt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:45:37 by qdeviann          #+#    #+#             */
/*   Updated: 2024/08/25 00:34:51 by bapt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	render_weapon(t_mlx *mlx, void *img_1, void *img_2, t_xy *pos)
{
	my_put_image(mlx, pos, &(t_wh){256, 256, 1}, img_1);
	if (mlx->player->keys->mouse_click == 1)
	{
		fov_details(mlx);
		my_put_image(mlx, pos, &(t_wh){256, 256, 1}, img_2);
	}
}
