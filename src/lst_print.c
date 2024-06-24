/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:06:13 by baptiste          #+#    #+#             */
/*   Updated: 2024/06/24 18:24:36 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    lst_print_data(t_map *lst)
{
    ft_printf_fd(1, BOLDYELLOW"-> CUB3D VAR <-\n\n"RESET);
    ft_printf_fd(1, BOLDGREEN"----DATA MAP----\n"RESET);
    ft_printf_fd(1, BOLDCYAN"NO : "RESET "%s", lst->data_map->no);
    ft_printf_fd(1, BOLDCYAN"SO : "RESET "%s", lst->data_map->so);
    ft_printf_fd(1, BOLDCYAN"WE : "RESET "%s", lst->data_map->we);
    ft_printf_fd(1, BOLDCYAN"EA : "RESET "%s", lst->data_map->ea);
    printf(BOLDCYAN"F : "RESET "0x%u\n", lst->data_map->floor_c);
    printf(BOLDCYAN"C : "RESET "0x%u\n", lst->data_map->sky_c);
    ft_printf_fd(1, BOLDCYAN"WIDTH : "RESET"%d\n", lst->data_map->width);
    ft_printf_fd(1, BOLDCYAN"HEIGHT : "RESET"%d\n", lst->data_map->height);
    ft_printf_fd(1, BOLDGREEN"----MAP----\n"RESET);
    print_tab(lst->map);
    ft_printf_fd(1, BOLDGREEN"\n----------------\n"RESET);
    ft_printf_fd(1, BOLDYELLOW"-> CONTROLS <-\n\n"RESET);
    ft_printf_fd(1, BOLDCYAN"Move : "RESET"WASD\n");
    ft_printf_fd(1, BOLDCYAN"Look : "RESET"ARROWS\n");
    ft_printf_fd(1, BOLDCYAN"Exit : "RESET"ESC\n");
    ft_printf_fd(1, BOLDCYAN"Show Map : "RESET"M\n");
    ft_printf_fd(1, BOLDGREEN"----------------\n"RESET); 
}
