/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <qdeviann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:49:02 by bapasqui          #+#    #+#             */
/*   Updated: 2024/08/12 10:36:30 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int rendering(void *param)
{
	t_mlx	*mlx;

	mlx = param;
	fov_details(mlx);
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
	print_banner();
	lst_print_data(mlx->map);
	fov_details(mlx);
	get_user_input(mlx);
	mlx_loop(mlx->mlx);
	ft_printf_message(END_OF_EXEC);
	free_all(&mlx);
}
