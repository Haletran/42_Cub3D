/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:13:14 by bapasqui          #+#    #+#             */
/*   Updated: 2024/06/24 16:23:17 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_user_input(t_mlx *mlx)
{
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, window_hook, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, ft_close, mlx);
}

int	window_hook(int event, void *param)
{
	t_mlx	*mlx;

	mlx = param;
	if (event == KEY_ESC)
		mlx_loop_end(mlx->mlx);
	return (0);
}

int	ft_close(t_mlx *mlx)
{
    mlx_loop_end(mlx->mlx);
    return (0);
}
