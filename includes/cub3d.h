/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:02:49 by bapasqui          #+#    #+#             */
/*   Updated: 2024/06/05 23:08:08 by baptiste         ###   ########.fr       */
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
# define RAYS 1000
# define PI 3.14159265358979323846
//# define RAYS_SIZE 100

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 500

# define SUCCESS 0
# define ERROR 1


# define SUCCESS 0
# define ERROR 1
# define ARG_ERROR -20
# define NO_FILE -30
# define NOT_CUB -90
# define NOT_VALID -40
# define UNKNOWN -50
# define MALLOC_ERROR -70
# define ERROR_IMAGE -80
# define FD_ERROR -100
# define NOTHING -110

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
	int				eye_h;
	double			angle;
	double			save;
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
	int 			print;
}					t_map;

typedef struct s_ray
{
	int				rayon;
	double			ray_angle;
	float			x;
	float			y;
	float			delta_x;
	float			delta_y;
	double			dir;
	double			dist;
}					t_ray;

/* FUNCTIONS */
void				draw_map(t_mlx *mlx);
int 				init_map(t_mlx *mlx);
void				rotate_fov(t_mlx *mlx);
void	rotate_line(t_mlx *mlx, int r);
void				free_tab(char **tab);
int 				init(t_mlx **mlx, char **str);
int					window_hook(int event, void *param);
int					key_hook(int key, void *param);
int					ft_close(int event, void *param);
void				free_all(t_mlx **mlx);
void				get_user_input(t_mlx *mlx);
int					get_map_len(char *path);
void				basic_direction(char *key, t_mlx *mlx);
void				rotation_direction(char *direction, t_mlx *mlx);
void    draw_wall(t_mlx *mlx, double x, double y, int r);
int					ft_error(int choice);


#endif