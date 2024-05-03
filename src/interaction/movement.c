/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:24:46 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/19 11:07:51 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void rotate_player(t_mlx *mlx)
{
    int steps = 20;
    double m = mlx->player->delta_y / mlx->player->delta_x;
    int i = 0;
    while (i < steps + 50) {
        double x = mlx->player->x + i * mlx->player->delta_x / steps;
        double y = mlx->player->y + m * i * mlx->player->delta_x / steps;
        mlx_pixel_put(mlx->mlx, mlx->win, x + 4, y + 3, 0xFFE8FF00);
        i++;
    }
}