/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:49:02 by bapasqui          #+#    #+#             */
/*   Updated: 2024/05/23 20:22:25 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc < 2)
		return (ERROR);
	mlx = ft_calloc(1, sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx = init(mlx, argv);
	if (!mlx)
		return (ERROR);
	mlx->win = mlx_new_window(mlx->mlx, 920, 580, "Cub3D");
	draw_map(mlx);
	rotate_fov(mlx);
   	// render_player(mlx);
	get_user_input(mlx);
	mlx_loop(mlx->mlx);
	free_all(&mlx);
}
