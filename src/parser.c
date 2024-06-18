/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:21:15 by baptiste          #+#    #+#             */
/*   Updated: 2024/06/18 23:23:27 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int check_data_map(t_data_map *data_map)
{
    if (!data_map->no || !data_map->so || !data_map->we
        || !data_map->ea || !data_map->floor_char || !data_map->sky_char)
        return (ft_error(DATA_ERROR));
    if (access(data_map->no, F_OK) == -1 || access(data_map->so, F_OK) == -1
        || access(data_map->we, F_OK) == -1 || access(data_map->ea, F_OK) == -1)
        return (ft_error(PATH_ERROR));
    return (SUCCESS);
}

int init_map(t_mlx *mlx)
{
    int i;
    int j;

    i = mlx->map->start_map;
    j = 0;
    mlx->map->map = ft_calloc(sizeof(char *), mlx->map->file_lenght - i + 1);
    if (!mlx->map->map)
        return (ft_error(MALLOC_ERROR));
    while (mlx->map->file[i])
    {
        mlx->map->map[j] = ft_strdup(mlx->map->file[i]);
        j++;
        i++;
    }
    free_tab(mlx->map->file);
    mlx->map->map[j] = NULL;
    return (SUCCESS);
}

int convert_rgb_to_hex(char *color)
{
    int r;
    int g;
    int b;

    r = ft_atoi(color);
    while (*color && *color != ',')
        color++;
    color++;
    g = ft_atoi(color);
    while (*color && *color != ',')
        color++;
    color++;
    b = ft_atoi(color);
    return (r << 16 | g << 8 | b);
}