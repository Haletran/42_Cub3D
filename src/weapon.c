/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <qdeviann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:45:37 by qdeviann          #+#    #+#             */
/*   Updated: 2024/08/18 20:43:36 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    render_weapon(t_mlx *mlx)
{
    my_put_image(mlx, &(t_xy){WINDOW_HEIGHT - 256, WINDOW_WIDTH / 2}, &(t_wh){256, 256, 1}, mlx->weapon->knife_0);
    if (mlx->player->keys->mouse_click == 1)
    {
        fov_details(mlx);
        my_put_image(mlx, &(t_xy){WINDOW_HEIGHT - 256, WINDOW_WIDTH / 2}, &(t_wh){256, 256, 1}, mlx->weapon->knife_1);
    }
}