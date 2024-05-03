/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:25:15 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/19 11:54:53 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void init_map(t_mlx *mlx)
{
    int fd;
    int i;

    i = 0;
    fd = open(mlx->map->path, O_RDONLY);
    if (!fd)
        return ;
    while (1)
    {
        mlx->map->map[i] = get_next_line(fd);
        if (!mlx->map->map[i])
            break;
        i++;
    }
    close(fd);
    draw_map(mlx);
}

void draw_map(t_mlx *mlx)
{
    int i;
    int j;

    i = 0;
    while (mlx->map->map[i])
    {
        j = 0;
        while (mlx->map->map[i][j])
        {
            if (mlx->map->map[i][j] == '1')
                mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wall, j * 33, i * 33);
            else if (mlx->map->map[i][j] == '0' || mlx->map->map[i][j] == 'W')
                mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->floor, j * 33, i * 33);
            else if (mlx->map->map[i][j] == 'E')
                mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->floor, j * 33, i * 33);
            j++;
        }
        i++;
    }
}
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

void draw_rays(t_mlx *mlx)
{
    int i;
    int dof;
    int yo;
    int xo;
    int mx; 
    int my;
    int map_width = 18;
    int map_height = 7;
    i = 0;

    mlx->ray->raise_angle = mlx->player->angle;
    while (i < 1)
    {
        // Horizontal
        dof = 0;
        mlx->ray->aTan = -1 / tan(mlx->player->angle);        
        if (mlx->player->angle > PI )
        {
            mlx->ray->y = (((int)mlx->player->y / 64) * 64) - 0.0001;
            mlx->ray->x = (mlx->player->y - mlx->ray->y) * mlx->ray->aTan + mlx->player->x;
            yo = -64;
            xo = -yo * mlx->ray->aTan;
        }
        else if (mlx->player->angle < PI )
        {
            mlx->ray->y = (((int)mlx->player->y / 64) * 64) + 64;
            mlx->ray->x = (mlx->player->y - mlx->ray->y) * mlx->ray->aTan + mlx->player->x;
            yo = 64;
            xo = -yo * mlx->ray->aTan;
        }
        else
        {
            mlx->ray->x = mlx->player->x;
            mlx->ray->y = mlx->player->y;
            dof = 8;
        }        
        while (dof < 8)
        {
            mx = (int)mlx->ray->x / 64;
            my = (int)mlx->ray->y / 64;
            if (mx < 0 || mx >= map_width || my < 0 || my >= map_height)
            {
                mlx->ray->x = mlx->player->x;
                mlx->ray->y = mlx->player->y;
                break;
            }
            else if (mlx->map->map[my][mx] == '1')
            {
                mlx->ray->x = mlx->ray->x + xo;
                mlx->ray->y = mlx->ray->y + yo;
                break;
            }
            else
            {
                mlx->ray->x += xo;
                mlx->ray->y += yo;
                dof += 1;
            }
        }
        // Vertical
        dof = 0;
        mlx->ray->aTan = -tan(mlx->player->angle);
        if (mlx->player->angle > PI / 2 && mlx->player->angle < 3 * PI / 2)
        {
            mlx->ray->x = (((int)mlx->player->x / 64) * 64) - 0.0001;
            mlx->ray->y = (mlx->player->x - mlx->ray->x) * mlx->ray->aTan + mlx->player->y;
            xo = -64;
            yo = -xo * mlx->ray->aTan;
        }
        else if (mlx->player->angle < PI / 2 || mlx->player->angle > 3 * PI / 2)
        {
            mlx->ray->x = (((int)mlx->player->x / 64) * 64) + 64;
            mlx->ray->y = (mlx->player->x - mlx->ray->x) * mlx->ray->aTan + mlx->player->y;
            xo = 64;
            yo = -xo * mlx->ray->aTan;
        }
        else
        {
            mlx->ray->x = mlx->player->x;
            mlx->ray->y = mlx->player->y;
            dof = 8;
        }
        while (dof < 8)
        {
            mx = (int)mlx->ray->x / 64;
            my = (int)mlx->ray->y / 64;
            if (mx < 0 || mx >= map_width || my < 0 || my >= map_height)
            {
                mlx->ray->x = mlx->player->x;
                mlx->ray->y = mlx->player->y;
                break;
            }
            else if (mlx->map->map[my][mx] == '1')
            {
                mlx->ray->x = mlx->ray->x + xo;
                mlx->ray->y = mlx->ray->y + yo;
                break;
            }
            else
            {
                mlx->ray->x += xo;
                mlx->ray->y += yo;
                dof += 1;
            }
        }  
        i++;
    } 
    draw_line(mlx, mlx->player->x, mlx->player->y, mlx->ray->x, mlx->ray->y, 0xFF223344); 
}
