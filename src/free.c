/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:42:08 by baptiste          #+#    #+#             */
/*   Updated: 2024/08/19 18:41:35 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*free_char(char *str)
{
	if (!str)
		return (NULL);
	free(str);
	str = NULL;
	return (NULL);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void	free_images(t_mlx **mlx)
{
	if ((*mlx)->img_n)
	{
		mlx_destroy_image((*mlx)->mlx, (*mlx)->img_n->img);
		free((*mlx)->img_n);
	}
	if ((*mlx)->img_s)
	{
		mlx_destroy_image((*mlx)->mlx, (*mlx)->img_s->img);
		free((*mlx)->img_s);
	}
	if ((*mlx)->img_w)
	{
		mlx_destroy_image((*mlx)->mlx, (*mlx)->img_w->img);
		free((*mlx)->img_w);
	}
	if ((*mlx)->img_e)
	{
		mlx_destroy_image((*mlx)->mlx, (*mlx)->img_e->img);
		free((*mlx)->img_e);
	}
	free_char((*mlx)->map->data_map->no);
	free_char((*mlx)->map->data_map->so);
	free_char((*mlx)->map->data_map->ea);
	free_char((*mlx)->map->data_map->we);
}

void	free_all(t_mlx **mlx)
{
	free_images(mlx);
	free_char((*mlx)->map->data_map->floor_char);
	free_char((*mlx)->map->data_map->sky_char);
	if ((*mlx)->map->path)
		free_char((*mlx)->map->path);
	free_tab((*mlx)->map->map);
	free_tab((*mlx)->map->file);
	if ((*mlx)->minimap)
		free((*mlx)->minimap);
	if ((*mlx)->map->data_map)
		free((*mlx)->map->data_map);
	if ((*mlx)->map)
		free((*mlx)->map);
	if ((*mlx)->player->keys)
		free((*mlx)->player->keys);
	if ((*mlx)->player)
		free((*mlx)->player);
	if ((*mlx)->ray)
		free((*mlx)->ray);
	if ((*mlx)->win)
		mlx_destroy_window((*mlx)->mlx, (*mlx)->win);
	mlx_destroy_display((*mlx)->mlx);
	free((*mlx));
}
