/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:49:02 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/19 11:58:05 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
    if (argc < 2)
        return (0);
    t_mlx *mlx;
    
    mlx = ft_calloc(1, sizeof(t_mlx));
    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, 18 * 33, 7 * 33 , "Cub3D");
    
    printf("%s", argv[1]);
    mlx = init(mlx, argv);
    init_map(mlx);
    rotate_player(mlx);
    render_player(mlx);
    
    mlx_set_fps_goal(mlx->mlx, 60);
	mlx_on_event(mlx->mlx, mlx->win, MLX_KEYDOWN, key_hook, mlx);
	mlx_on_event(mlx->mlx, mlx->win, MLX_WINDOW_EVENT, window_hook, mlx);
    mlx_loop(mlx->mlx);
    mlx_destroy_window(mlx->mlx, mlx->win);
    mlx_destroy_display(mlx->mlx);
    free_tab(mlx->map->map);
    free(mlx->map);
    free(mlx->player);
}