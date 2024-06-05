/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:42:08 by baptiste          #+#    #+#             */
/*   Updated: 2024/06/05 23:08:39 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*free_char(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_all(t_mlx **mlx)
{
	mlx_destroy_image((*mlx)->mlx, (*mlx)->floor);
	mlx_destroy_image((*mlx)->mlx, (*mlx)->wall);
	mlx_destroy_window((*mlx)->mlx, (*mlx)->win);
	mlx_destroy_display((*mlx)->mlx);
	free_tab((*mlx)->map->map);
	(*mlx)->map->path = free_char((*mlx)->map->path);
	free((*mlx)->map);
	free((*mlx)->player);
	free((*mlx)->ray);
	free((*mlx)->mlx);
	free((*mlx));
}
