/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:14:46 by bapasqui          #+#    #+#             */
/*   Updated: 2024/07/10 01:43:27 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_error(int choice)
{
	if (!choice)
		ft_printf_fd(2, BOLDRED "[ ERROR ] : " RESET "Unknown error\n");
	if (choice == ERROR_IMAGE)
		ft_printf_fd(2, BOLDRED "[ ERROR ] : " RESET "image initialisation\n");
	else if (choice == MALLOC_ERROR)
		ft_printf_fd(2, BOLDRED "[ ERROR ] : " RESET "stack initialisation\n");
	else if (choice == NOT_CUB)
		ft_printf_fd(2, BOLDRED "[ ERROR ] : " RESET "not a map in .cub\n");
	else if (choice == NOT_VALID)
		ft_printf_fd(2, BOLDRED "[ ERROR ] : " RESET "map not valid\n");
	else if (choice == FD_ERROR)
		ft_printf_fd(2, BOLDRED "[ ERROR ] : " RESET "fd not existing\n");
	else if (choice == ARG_ERROR)
		ft_printf_fd(2,
			BOLDRED "[ ERROR ] : " RESET "Not enough arguments or too much\n");
	else if (choice == NO_FILE)
		ft_printf_fd(2, BOLDRED "[ ERROR ] : " RESET "File not found\n");
	else if (choice == UNKNOWN)
		ft_printf_fd(2, BOLDRED "[ ERROR ] : " RESET "Unknown error\n");
	else if (choice == NOTHING)
		ft_printf_fd(2, BOLDRED "[ ERROR ] : " RESET "Nothing in file\n");
	else if (choice == DATA_ERROR)
		ft_printf_fd(2, BOLDRED "[ ERROR ] : " RESET "Data map not valid\n");
	else if (choice == PATH_ERROR)
		ft_printf_fd(2,
			BOLDRED "[ ERROR ] : " RESET "Texture file not found\n");
	return (ERROR);
}
