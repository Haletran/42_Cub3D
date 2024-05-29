/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:49:02 by bapasqui          #+#    #+#             */
/*   Updated: 2024/05/29 22:28:34 by bapasqui         ###   ########.fr       */
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
	mlx->win = mlx_new_window(mlx->mlx, 800, 300, "Cub3D");
	draw_map(mlx);
	rotate_fov(mlx);
	get_user_input(mlx);
	mlx_loop(mlx->mlx);
	free_all(&mlx);
}
