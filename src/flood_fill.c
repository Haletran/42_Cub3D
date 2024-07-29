/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 03:24:59 by bapt              #+#    #+#             */
/*   Updated: 2024/07/29 21:04:32 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void   flood_fill(char **map, t_mlx *mlx, int x, int y)
{
    if (x < 0 || x >= get_maxlenght(map) - 1 || y < 0 || y >= get_width(map))
        return ;
    if (map[y][x] == '1' || map[y][x] == 'x')
        return ;
    if (map[y][x] == 3)
    {
        mlx->flood_error = true;
        return ;
    }
    map[y][x] = 'x';
    flood_fill(map, mlx, x + 1, y);
    flood_fill(map, mlx, x - 1, y);
    flood_fill(map, mlx, x, y + 1);
    flood_fill(map, mlx, x, y - 1);
}