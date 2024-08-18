/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <qdeviann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:13:14 by bapasqui          #+#    #+#             */
/*   Updated: 2024/08/18 19:48:00 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	reset_keys(int event, void *param)
{
	t_mlx	*mlx;

	mlx = param;
	if (event == W_KEY)
		mlx->player->keys->w = 0;
	if (event == A_KEY)
		mlx->player->keys->a = 0;
	if (event == S_KEY)
		mlx->player->keys->s = 0;
	if (event == D_KEY)
		mlx->player->keys->d = 0;
	if (event == SHIFT_KEY)
	{
		mlx->player->keys->shift = 0;
		mlx->player->speed = PLAYER_SPEED;
	}
	if (event == LEFT_ARROW)
		mlx->player->keys->left = 0;
	if (event == RIGHT_ARROW)
		mlx->player->keys->right = 0;
	return (0);
}


int mouse_hook(int button, void *param)
{
	t_mlx *mlx;

	mlx = param;
	if (button == 1)
		mlx->player->keys->mouse_click = 1;
	return (0);
}

int mouse_reset(int button, void *param)
{
	t_mlx *mlx;

	mlx = param;
	(void)button;
	if (mlx->player->keys->mouse_click == 1)
		mlx->player->keys->mouse_click = 0;
	return (0);
}


void	get_user_input(t_mlx *mlx)
{
	mlx_on_event(mlx->mlx, mlx->win, MLX_KEYDOWN, keydown_keys, mlx);
	mlx_on_event(mlx->mlx, mlx->win, MLX_KEYUP, reset_keys, mlx);
	mlx_on_event(mlx->mlx, mlx->win, MLX_WINDOW_EVENT, ft_close, mlx);
	mlx_on_event(mlx->mlx, mlx->win, MLX_MOUSEDOWN, mouse_hook, mlx);
    mlx_on_event(mlx->mlx, mlx->win, MLX_MOUSEUP, mouse_reset, mlx);
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
