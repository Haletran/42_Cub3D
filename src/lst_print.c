/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:06:13 by baptiste          #+#    #+#             */
/*   Updated: 2024/08/19 19:27:18 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_banner(void)
{
	ft_printf_fd(1, BOLDGREEN_HI "   ___      _          _____   ___ \n");
	ft_printf_fd(1, "  / __\\   _| |__   ___|___ /  /   \\ \n");
	ft_printf_fd(1, " / / | | | | '_ \\ / _ \\ |_ \\ / /\\ / \n");
	ft_printf_fd(1, "/ /__| |_| | |_) |  __/___) / /_//  \n");
	ft_printf_fd(1, "\\____/\\__,_|_.__/ \\___|____/___,'   \n" RESET);
	ft_printf_fd(1, "                                    \n");
	ft_printf_fd(1, BOLDMAGENTA "    by bapasqui & qdeviann\n\n" RESET);
}

void	lst_print_data(t_map *lst)
{
	if (DEBUG_INFO == 1)
	{
		ft_printf_fd(1, BOLDGREEN "----DATA MAP----\n" RESET);
		ft_printf_fd(1, BOLDCYAN "NO : " RESET "%s\n", lst->data_map->no);
		ft_printf_fd(1, BOLDCYAN "SO : " RESET "%s\n", lst->data_map->so);
		ft_printf_fd(1, BOLDCYAN "WE : " RESET "%s\n", lst->data_map->we);
		ft_printf_fd(1, BOLDCYAN "EA : " RESET "%s\n", lst->data_map->ea);
		printf(BOLDCYAN "F : " RESET "0x%X\n", lst->data_map->floor_c);
		printf(BOLDCYAN "C : " RESET "0x%X\n", lst->data_map->sky_c);
		ft_printf_fd(1, BOLDGREEN "----MAP----\n" RESET);
		print_tab(lst->map);
	}
	ft_printf_fd(1, BOLDGREEN "---CONTROLS---\n" RESET);
	ft_printf_fd(1, BOLDCYAN "W : " RESET "Move forward\n");
	ft_printf_fd(1, BOLDCYAN "S : " RESET "Move backward\n");
	ft_printf_fd(1, BOLDCYAN "A : " RESET "Move left\n");
	ft_printf_fd(1, BOLDCYAN "D : " RESET "Move right\n");
	ft_printf_fd(1, BOLDCYAN "← : " RESET "Rotate left\n");
	ft_printf_fd(1, BOLDCYAN "→ : " RESET "Rotate right\n");
	ft_printf_fd(1, BOLDCYAN "ESC : " RESET "Quit\n");
	ft_printf_fd(1, BOLDGREEN "----------------\n" RESET);
}

void	ft_printf_message(char *message)
{
	ft_printf_fd(1, BOLDYELLOW "%s\n" RESET, message);
}
