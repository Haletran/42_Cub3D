/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:02:49 by bapasqui          #+#    #+#             */
/*   Updated: 2024/06/04 14:01:30 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft.h"
# include "../minilibx/mlx.h"
# include "colors.h"
# include "mlx_keys.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* DEFINE */
# define FOV 60
# define RAYS 10
# define PI 3.14159265358979323846
# define RAYS_SIZE 500

# define WINDOW_WIDHT 1920
# define WINDOW_HEIGHT 1080

# define SUCCESS 0
# define ERROR 1

/*STRUCTURES*/

typedef enum s_message
{
	NO_OPTION,
	NO_FILE,
	NOT_VALID,
	UNKNOWN,
	MALLOC,
}					t_message;

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
	t_message		*error;
}					t_mlx;

typedef struct s_player
{
	float			x;
	float			y;
	float			delta_x;
	float			delta_y;
	double			angle;
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
	int				lenght;
	int				backup_fd;
}					t_map;

typedef struct s_ray
{
	int				rayon;
	double			ray_angle;
	float			x;
	float			y;
	float			hx;
	float			hy;
	double			dir;
	double			dist;
}					t_ray;

/* FUNCTIONS */
void				draw_map(t_mlx *mlx);
void				init_map(t_mlx *mlx);
void				rotate_fov(t_mlx *mlx);
void	rotate_line(t_mlx *mlx, int r);
void				free_tab(char **tab);
t_mlx				*init(t_mlx *mlx, char **str);
int					window_hook(int event, void *param);
int					key_hook(int key, void *param);
int					ft_close(int event, void *param);
void				free_all(t_mlx **mlx);
void				get_user_input(t_mlx *mlx);
int					get_map_len(char *path);
void				basic_direction(char *key, t_mlx *mlx);
void				rotation_direction(char *direction, t_mlx *mlx);
void    draw_wall(t_mlx *mlx, double x, double y, int r);

#endif