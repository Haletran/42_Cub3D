/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:49:02 by bapasqui          #+#    #+#             */
/*   Updated: 2024/08/18 23:04:36 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	move_render(void *param)
{
	t_mlx			*mlx;

	mlx = (t_mlx *)param;
	move_player(mlx);
	rotate_player(mlx);
	fov_details(mlx);
	render_weapon(mlx);
	my_put_image(mlx, &(t_xy){WINDOW_HEIGHT / 2 - 30, WINDOW_WIDTH / 2 - 64},
		&(t_wh){64, 64, 1}, mlx->weapon->crosshair);
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
	mlx_mouse_hide();
	mlx_mouse_move(mlx->mlx, mlx->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	print_banner();
	lst_print_data(mlx->map);
	get_user_input(mlx);
	mlx_loop_hook(mlx->mlx, &move_render, mlx);
	mlx_loop(mlx->mlx);
	ft_printf_message(END_OF_EXEC);
	free_all(&mlx);
}
