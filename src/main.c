/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:49:02 by bapasqui          #+#    #+#             */
/*   Updated: 2024/08/12 17:22:54 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <time.h>

void render_fps_box(t_mlx *mlx, int fps)
{
	void *box;

	box = mlx_new_image(mlx->mlx, 100, 100);
	my_put_image(mlx, &(t_xy){0, 0}, &(t_wh){90, 20, 0}, box);
	mlx_string_put(mlx->mlx, mlx->win, 10, 10, 0xFFFFFFFF, "FPS:");
	mlx_string_put(mlx->mlx, mlx->win, 50, 10, 0xFFFFFFFF, ft_itoa(fps));
	mlx_destroy_image(mlx->mlx, box);
}

int move_render(void *param)
{
    static clock_t last_time = 0;
    clock_t current_time;
    double fps;
    t_mlx *mlx;

    mlx = (t_mlx *)param;
    move_player(mlx);
    rotate_player(mlx);
    fov_details(mlx);
    current_time = clock();
    fps = CLOCKS_PER_SEC / (double)(current_time - last_time);
    last_time = current_time;
	render_fps_box(mlx, fps);
    return (SUCCESS);
}


int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc < 2)
		return (ft_error(ARG_ERROR));
	mlx = ft_calloc(1, sizeof(t_mlx));
	mlx->mlx = mlx_init();
	if (init(&mlx, argv) != SUCCESS)
	{
		free_all(&mlx);
		return (ERROR);
	}
	mlx->win = mlx_new_window(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, GAME_NAME);
	if (!mlx->win)
		return (ERROR);
	mlx_set_fps_goal(mlx->mlx, 80);
	print_banner();
	lst_print_data(mlx->map);
	get_user_input(mlx);
	mlx_loop_hook(mlx->mlx, &move_render, mlx);
	mlx_loop(mlx->mlx);
	ft_printf_message(END_OF_EXEC);
	free_all(&mlx);
}
