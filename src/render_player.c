/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:25:19 by bapasqui          #+#    #+#             */
/*   Updated: 2024/05/23 15:54:36 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void draw_line(t_mlx *mlx, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy;
    int e2;

    while (1)
    {
        mlx_pixel_put(mlx->mlx, mlx->win, x0, y0, color);
        if (x0 == x1 && y0 == y1)
            break;
        e2 = 2 * err;
        if (e2 >= dy)
        {
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void    render_player(t_mlx *mlx)
{	
    int 	i;
	int		limit;
	int 	ysize;
	int		xsize;
    int 	mx; 
    int 	my;
	int		vx;
	int		vy;
	int		PA;
	int		PB;

    i = 0;
    mlx_pixel_put(mlx->mlx, mlx->win, mlx->player->x, mlx->player->y, 0xFF0000);
    while (i < 1)
    {
        // Horizontal
		limit = 0;
        mlx->ray->aTan = -1 / tan(mlx->player->angle);        
        if (mlx->player->angle > PI )
        {
            mlx->ray->y = (((int)mlx->player->y / 32) * 32) - 0.1;
            mlx->ray->x = (mlx->player->y - mlx->ray->y) * mlx->ray->aTan + mlx->player->x;
            ysize = -32;
            xsize = -ysize * mlx->ray->aTan;
        }
        else if (mlx->player->angle < PI )
        {
            mlx->ray->y = (((int)mlx->player->y / 32) * 32) + 32;
            mlx->ray->x = (mlx->player->y - mlx->ray->y) * mlx->ray->aTan + mlx->player->x;
            ysize = 32;
            xsize = -ysize * mlx->ray->aTan;
        }
        else
        {
            mlx->ray->x = mlx->player->x;
            mlx->ray->y = mlx->player->y;
            limit = mlx->map->width;
        }        
        while (limit < mlx->map->width)
        {
            mx = (int)mlx->ray->x / 32;
            my = (int)mlx->ray->y / 32;
            if (mx < 0 || mx >= mlx->map->width || my < 0 || my >= mlx->map->height)
            {
                mlx->ray->x = mlx->player->x;
                mlx->ray->y = mlx->player->y;
                break;
            }
            else if (mlx->map->map[my][mx] == '1')
            {
                mlx->ray->x = mlx->ray->x + xsize;
                mlx->ray->y = mlx->ray->y + ysize;
                break;
            }
            else
            {
                mlx->ray->x += xsize;
                mlx->ray->y += ysize;
                limit += 1;
            }
        }
        // Vertical
        limit = 0;
        mlx->ray->aTan = -tan(mlx->player->angle);
        if (mlx->player->angle < PI)
        {
            mlx->ray->hx = (((int)mlx->player->x / 32) * 32) - 0.1;
            mlx->ray->hy = (mlx->player->x - mlx->ray->hx) * mlx->ray->aTan + mlx->player->y;
            xsize = -32;
            ysize = -xsize * mlx->ray->aTan;
        }
        else if (mlx->player->angle > PI)
        {
            mlx->ray->hx = (((int)mlx->player->x / 32) * 32) + 32;
            mlx->ray->hy = (mlx->player->x - mlx->ray->hx) * mlx->ray->aTan + mlx->player->y;
            xsize = 32;
            ysize = -xsize * mlx->ray->aTan;
        }
        else
        {
            mlx->ray->hx = mlx->player->x;
            mlx->ray->hy = mlx->player->y;
            limit = mlx->map->height;
        }
        while (limit < mlx->map->height)
        {
            vx = (int)mlx->ray->hx / 32;
            vy = (int)mlx->ray->hy / 32;
            if (vx < 0 || vx >= mlx->map->width || vy < 0 || vy >= mlx->map->height)
            {
                mlx->ray->hx = mlx->player->x;
                mlx->ray->hy = mlx->player->y;
                break;
            }
            else if (mlx->map->map[vy][vx] == '1')
            {
                mlx->ray->hx = mlx->ray->hx + xsize;
                mlx->ray->hy = mlx->ray->hy + ysize;
                break;
            }
            else
            {
                mlx->ray->hx += xsize;
                mlx->ray->hy += ysize;
                limit += 1;
            }
        }  
        i++;
    } 
	PA = abs((int)mlx->player->x - mx) / cos(mlx->player->angle);
	PB = abs((int)mlx->player->x - vx) / cos(mlx->player->angle);
	if (PA < PB)
   		draw_line(mlx, mlx->player->x, mlx->player->y, mlx->ray->x, mlx->ray->y, 0xFF223344); 
	else
   		draw_line(mlx, mlx->player->x, mlx->player->y, mlx->ray->hx, mlx->ray->hy, 0xFF223344); 
}
