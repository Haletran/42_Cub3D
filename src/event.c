/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:13:14 by bapasqui          #+#    #+#             */
/*   Updated: 2024/05/29 22:50:07 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_user_input(t_mlx *mlx)
{
	mlx_on_event(mlx->mlx, mlx->win, MLX_KEYDOWN, key_hook, mlx);
	mlx_on_event(mlx->mlx, mlx->win, MLX_WINDOW_EVENT, ft_close, mlx);
	//mlx_key_hook(mlx->win, key_hook, mlx);
	//mlx_hook(mlx->win, 2, 1L << 0, window_hook, mlx);
	//mlx_hook(mlx->win, 17, 0, ft_close, mlx);
}

int	window_hook(int event, void *param)
{
	t_mlx	*mlx;

	mlx = param;
	if (event == KEY_ESC)
		mlx_loop_end(mlx->mlx);
	return (0);
}

int	ft_close(int event, void *param)
{
	t_mlx	*mlx;

	(void)event;
	mlx = param;
	if (event == 0)
		mlx_loop_end(mlx->mlx);
	return (0);
}

