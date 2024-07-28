/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapt <bapt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:06:13 by baptiste          #+#    #+#             */
/*   Updated: 2024/07/28 03:10:43 by bapt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	lst_print_data(t_map *lst)
{
	ft_printf_fd(1, BOLDGREEN "----DATA MAP----\n" RESET);
	ft_printf_fd(1, BOLDCYAN "NO : " RESET "%s\n", lst->data_map->no);
	ft_printf_fd(1, BOLDCYAN "SO : " RESET "%s\n", lst->data_map->so);
	ft_printf_fd(1, BOLDCYAN "WE : " RESET "%s\n", lst->data_map->we);
	ft_printf_fd(1, BOLDCYAN "EA : " RESET "%s\n", lst->data_map->ea);
	printf(BOLDCYAN "F : " RESET "0x%u\n", lst->data_map->floor_c);
	printf(BOLDCYAN "C : " RESET "0x%u\n", lst->data_map->sky_c);
	ft_printf_fd(1, BOLDGREEN "----MAP----\n" RESET);
	print_tab(lst->map);
    ft_printf_fd(1, BOLDGREEN "\n----------------\n" RESET);
}
