/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:49:02 by bapasqui          #+#    #+#             */
/*   Updated: 2024/06/05 23:08:09 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc < 2)
		return (ft_error(ARG_ERROR));
	mlx = ft_calloc(1, sizeof(t_mlx));
	mlx->mlx = mlx_init();
	if (init(&mlx, argv) != SUCCESS)
		return (ERROR);
	mlx->win = mlx_new_window(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	if (!mlx->win)
		return (ERROR);
	lst_print_data(mlx->map);
	draw_map(mlx);
	fov_details(mlx);
	get_user_input(mlx);
	mlx_loop(mlx->mlx);
	//free_all(&mlx);
}
