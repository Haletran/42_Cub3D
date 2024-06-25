/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:21:15 by baptiste          #+#    #+#             */
/*   Updated: 2024/06/25 17:08:13 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int check_data_map(t_data_map *data_map)
{
    if (!data_map->no || !data_map->so || !data_map->we
        || !data_map->ea || !data_map->floor_char || !data_map->sky_char)
        return (ft_error(DATA_ERROR));
        // change to open
/*     if (open(data_map->no, F_OK) == -1 || open(data_map->so, F_OK) == -1
        || open(data_map->we, F_OK) == -1 || open(data_map->ea, F_OK) == -1)
        return (ft_error(PATH_ERROR)); */
    return (SUCCESS);
}

int check_map_validity(t_mlx *mlx)
{
    int i;
    int j;
    int last_line;

    i = 0;
    j = 0;
    last_line = mlx->map->data_map->height;
    while (mlx->map->map[0][i])
    {
        if (mlx->map->map[0][i] != '1')
        {
            if (mlx->map->map[0][i] == '\n')
                break;
            if (mlx->map->map[0][i] == 32 && mlx->map->map[1][i] == 0)
                return (ERROR);
            else if (mlx->map->map[0][i] != 32)
                return (ERROR);
        }    
        i++;
    }
    i = 0;
    while (mlx->map->map[last_line][i])
    {
        if (mlx->map->map[last_line][i] != '1')
        {
            if (mlx->map->map[last_line][i] == '\n')
                break;
            if (mlx->map->map[last_line][i] == 32 && mlx->map->map[last_line - 1][i] == 0)
                return (ERROR);
            else if (mlx->map->map[last_line][i] != 32)
                return (ERROR);
        }    
        i++;
    }
    i = 1;
    while(mlx->map->map[i])
    {
        j = 0;
        while (mlx->map->map[i][j] == 32)
            j++;
        printf("mlx->map %s", mlx->map->map[i]);
        if (mlx->map->map[i][j] != '1')
            return (ERROR);
        while (mlx->map->map[i][j] != '\n')
            j++;
        if (mlx->map->map[i][j - 1] != '1')
            return (ERROR);
        i++;
    }
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
        if (mlx->map->file[i][0] == '\n')
            i++;
        else
        {
            mlx->map->map[j] = ft_strdup(mlx->map->file[i]);
            j++;
            i++;
        }
    }
    free_tab(mlx->map->file);
    mlx->map->map[j] = NULL;
    get_map_dimension(mlx);
    if (check_map_validity(mlx) == ERROR)
        return (ft_error(NOT_VALID));
    return (SUCCESS);
}

int check_verif_color(char *color)
{
    int i;
    char **tmp;
    int j;

    i = 0;
    tmp = ft_split(color, ',');
    while(tmp[i])
    {
        j = 0;
        while (j < (int)ft_strlen(tmp[i]) - 1)
        {
            if (!ft_isdigit(tmp[i][j]))
            {
                free_tab(tmp);
                return (ERROR);
            }
            j++;
        }
        if (j < 1 || j > 3)
            return (free_tab(tmp), ERROR);
        i++;
    }
    free_tab(tmp);
    return (SUCCESS);
}

int convert_rgb_to_hex(char *color)
{
    int r;
    int g;
    int b;

    if (!color || check_verif_color(color) == ERROR)
        return (ft_error(DATA_ERROR));
    r = ft_atoi(color);
    while (*color && *color != ',')
        color++;
    color++;
    g = ft_atoi(color);
    while (*color && *color != ',')
        color++;
    color++;
    b = ft_atoi(color);
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
        return (ft_error(DATA_ERROR));
    return (r << 16 | g << 8 | b);
}
