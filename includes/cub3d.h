/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:02:49 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/19 11:22:16 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MacroLibX/includes/mlx.h"
# include "../lib/libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* DEFINE */
# define FOV 60
# define RAYS 300
# define PI 3.14159265358979323846

# define KEY_ESC 41
# define KEY_W 26
# define KEY_A 4
# define KEY_S 22
# define KEY_D 7

# define LEFT_ARROW 80
# define RIGHT_ARROW 79
# define UP_ARROW 82
# define DOWN_ARROW 81

/*STRUCTURES*/

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*floor;
	void			*wall;
	struct s_player	*player;
	struct s_ray	*ray;
	struct s_map	*map;
}					t_mlx;

typedef struct s_player
{
	float			x;
	float			y;
	float			delta_x;
	float			delta_y;
	float			angle;
	double			dir;
	double			fov;
}					t_player;

typedef struct s_map
{
	int				*map2;
	char			**map;
	int				width;
	int				height;
	char			*path;
}					t_map;

typedef struct s_ray
{
	int				rayon;
	float			x;
	float			y;
	float			raise_angle;
	float aTan;
	double			dir;
	double			dist;
}					t_ray;

/* FUNCTIONS */
void				draw_rays(t_mlx *mlx);
void 				draw_map(t_mlx *mlx);
void				init_map(t_mlx *mlx);
void				rotate_player(t_mlx *mlx);
void				free_tab(char **tab);
void				render_player(t_mlx *mlx);
t_mlx				*init(t_mlx *mlx, char **str);
int					window_hook(int event, void *param);
int					key_hook(int key, void *param);

#endif