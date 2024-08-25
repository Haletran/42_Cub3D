/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:49:02 by bapasqui          #+#    #+#             */
/*   Updated: 2024/08/25 15:27:43 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <time.h>

void	render_fps_box(t_mlx *mlx, int fps)
{
	void	*box;
	char	*fps_str;

	fps_str = ft_itoa(fps);
	box = mlx_new_image(mlx->mlx, 100, 100);
	my_put_image(mlx, &(t_xy){0, 0}, &(t_wh){80, 15, 0}, box);
	mlx_string_put(mlx->mlx, mlx->win, 10, 10, 0xFFFFFFFF, "FPS:");
	mlx_string_put(mlx->mlx, mlx->win, 50, 10, 0xFFFFFFFF, fps_str);
	mlx_destroy_image(mlx->mlx, box);
	fps_str = free_char(fps_str);
}

int	move_render(void *param)
{
	static clock_t	last_time = 0;
	clock_t			current_time;
	double			fps;
	t_mlx			*mlx;

	mlx = (t_mlx *)param;
	mlx_mouse_hide();
	move_player(mlx);
	rotate_player(mlx);
	fov_details(mlx);
	if (mlx->player->weapon == 1)
		render_weapon(mlx, mlx->weapon->knife_0, mlx->weapon->knife_1, &(t_xy){WINDOW_HEIGHT - 256, WINDOW_WIDTH / 2});
	else if (mlx->player->weapon == 0)
		render_weapon(mlx, mlx->weapon->pistol_0, mlx->weapon->pistol_1, &(t_xy){WINDOW_HEIGHT - 256, (WINDOW_WIDTH - 256) / 2});
	my_put_image(mlx, &(t_xy){(WINDOW_HEIGHT - 64) / 2, (WINDOW_WIDTH - 64) / 2},
        &(t_wh){64, 64, 1}, mlx->weapon->crosshair);
	if (mlx->player->fps_counter == 1)
	{
		current_time = clock();
		fps = CLOCKS_PER_SEC / (double)(current_time - last_time);
		last_time = current_time;
		render_fps_box(mlx, fps);
	}
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
	{
		free_all(&mlx);
		return (ERROR);
	}
	mlx_mouse_move(mlx->mlx, mlx->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	print_banner();
	lst_print_data(mlx->map);
	get_user_input(mlx);
	mlx_loop_hook(mlx->mlx, &move_render, mlx);
	mlx_loop(mlx->mlx);
	ft_printf_message(END_OF_EXEC);
	free_all(&mlx);
}
