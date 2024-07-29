/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:02:49 by bapasqui          #+#    #+#             */
/*   Updated: 2024/07/29 20:40:41 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MacroLibX/includes/mlx.h"
# include "../lib/libft.h"
# include "colors.h"
# include "error_msg.h"
# include "mlx_keys.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* DEFINE */
# define FOV 60
# define RAYS 920
# define PI 3.14159265358979323846
//# define RAYS_SIZE 100

# define WINDOW_WIDTH 920
# define WINDOW_HEIGHT 580

# define SUCCESS 0
# define ERROR 1

/*STRUCTURES*/

typedef struct s_xy
{
	int					x;
	int					y;
}						t_xy;

typedef struct s_wh
{
	int					w;
	int					h;
}						t_wh;

typedef enum s_key
{
	RIGHT,
	LEFT,
	W,
	A,
	S,
	D,
	M,
	ECHAP,
}						t_key;

typedef struct s_data_map
{
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*s;
	int					floor_c;
	int					sky_c;
	int					width;
	int					height;
	int					map_lenght;
	char				*floor_char;
	char				*sky_char;
}						t_data_map;

typedef struct s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	void				*floor;
	void				*wall;
	int					size;
	bool flood_error;
	struct s_player		*player;
	struct s_ray		*ray;
	struct s_map		*map;
	struct s_img		*img_n;
	struct s_img		*img_s;
	struct s_img		*img_w;
	struct s_img		*img_e;
	struct s_img		*debug_box;
	struct s_img		*minimap;
	struct s_img		*cadre;
}						t_mlx;

typedef struct s_player
{
	float				x;
	float				y;
	float				delta_x;
	float				delta_y;
	int					eye_h;
	double				angle;
	double				save;
	double				dir;
	double				fov;
	int					minimap;
	int					debug;
	t_key				key;
}						t_player;

typedef struct s_map
{
	struct s_data_map	*data_map;
	int					*map2;
	char				**map;
	char				**file;
	char				*path;
	int					file_lenght;
	int					backup_fd;
	int					print;
	int					start_map;
}						t_map;

typedef struct s_ray
{
	int					pix;
	int					h_hit;
	float				h_height;
	float				ray_angle;
	float				x;
	float				y;
	float				step_x;
	float				step_y;
	float				dist;
}						t_ray;

typedef struct s_img
{
	void				*img;
	int					t_wid;
	int					t_hei;

}						t_img;

/* FUNCTIONS */
void					draw_map(t_mlx *mlx);
int						init_map(t_mlx *mlx);
float					pythagoras(t_mlx *mlx, float x, float y);
void					free_tab(char **tab);
int						init(t_mlx **mlx, char **str);
int						window_hook(int event, void *param);
int						key_hook(int key, void *param);
int						ft_close(int event, void *param);
void					free_all(t_mlx **mlx);
void					get_user_input(t_mlx *mlx);
int						get_map_len(char *path);
void					basic_direction(char *key, t_mlx *mlx);
void					rotation_direction(char *direction, t_mlx *mlx);
void					draw_wall(t_mlx *mlx, int r);
int						ft_error(char *error);
void					fov_details(t_mlx *mlx);
int						attribute_data_map(t_mlx *mlx);
void					lst_print_data(t_map *lst);
int						check_data_map(t_data_map *data_map);
int						init_map(t_mlx *mlx);
int						convert_rgb_to_hex(char *color);
char					*free_char(char *str);
int						read_file(t_mlx *mlx);
int						check_if_charset(char c, char *charset);
int						check_map_validity(t_mlx *mlx, char **map);
void					get_player_data(t_mlx *mlx, int i, int j, char c);
void					print_banner(t_mlx *mlx);
int						map_is_closed(t_mlx *mlx);
void					lr_direction(char *key, t_mlx *mlx);
int						replace_space(t_mlx *mlx);
void					my_put_image(t_mlx *mlx, t_xy *xy, t_wh *wh, void *img,
							int check);
void					draw_ray(t_mlx *mlx);
void					draw_debug(t_mlx *mlx, t_xy *xy, t_wh *wh);
int						get_width(char **str);
char					**ft_copy_tab(char **src, char **dest);
int						get_maxlenght(char **str);
void   flood_fill(char **map, t_mlx *mlx, int x, int y);

#endif