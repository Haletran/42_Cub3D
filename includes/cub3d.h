/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapt <bapt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:02:49 by bapasqui          #+#    #+#             */
/*   Updated: 2024/08/25 00:01:04 by bapt             ###   ########.fr       */
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
# define GAME_NAME "Cub3D"
# define RAYS 920
# define PI 3.1415926535
# define TILL_S 64
# define WINDOW_WIDTH 920
# define WINDOW_HEIGHT 580
# define PLAYER_SPEED 5
# define DEBUG_INFO 1

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
	int					check;
}						t_wh;

typedef struct s_key
{
	bool				w;
	bool				a;
	bool				s;
	bool				d;
	bool				left;
	bool				right;
	bool				shift;
	bool				mouse_click;
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

typedef struct s_weapon
{
	void				*crosshair;
	void				*knife_0;
	void				*knife_1;
	void 				*pistol_0;
	void 				*pistol_1;
	int					width;
	int					height;
}						t_weapon;

typedef struct s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	int					size;
	bool				flood_error;
	int					counter;
	int					player_check;
	struct s_player		*player;
	struct s_ray		*ray;
	struct s_map		*map;
	struct s_img		*img_n;
	struct s_img		*img_s;
	struct s_img		*img_w;
	struct s_img		*img_e;
	struct s_weapon		*weapon;
	struct s_img		*minimap;
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
	int					fps_counter;
	int					debug;
	int					speed;
	int 				weapon;
	struct s_key		*keys;
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

// Initialization functions
int						init(t_mlx **mlx, char **str);
int						init_map(t_mlx **mlx);
int						init_player(t_mlx **mlx);
int						init_images(t_mlx **mlx);
int						init_textures(t_mlx **mlx);

// Player movement and input handling
int						move_player(void *param);
void					get_user_input(t_mlx *mlx);
void					basic_direction(char *key, t_mlx *mlx);
void					rotation_direction(char *direction, t_mlx *mlx);
void					lr_direction(char *key, t_mlx *mlx);
int						rotate_player(void *param);

// Drawing functions
void					draw_minimap(t_mlx *mlx);
void					draw_wall(t_mlx *mlx, int r);
void					draw_ray(t_mlx *mlx);
void					draw_square(t_mlx *mlx, int x, int y, int color);
void					draw_other(t_mlx *mlx, int ray_index, float start,
							float end);
void					draw_in_color(t_mlx *mlx, int ray_index, float start,
							float end);
void					my_put_image(t_mlx *mlx, t_xy *xy, t_wh *whc,
							void *img);
void	render_weapon(t_mlx *mlx, void *img_1, void *img_2, t_xy *pos);

// Raycasting and calculations
float					pythagoras(t_mlx *mlx, float x, float y);
void					fov_details(t_mlx *mlx);
int						calculate_tex_x(t_mlx *mlx, float wall_x);
float					calculate_step(t_mlx *mlx);
float					keep_circle(float angle);
float					get_vertical_hit(t_mlx *mlx);
float					get_horizontal_hit(t_mlx *mlx);
int						hit_wall(t_mlx *mlx, float x, float y);
void					init_step(t_mlx *mlx, float *inter, char c);
void					find_ray_lenght(t_mlx *mlx);

// Map validation and manipulation
int						get_map_len(char *path);
int						read_file(t_mlx *mlx);
int						check_if_charset(char c, char *charset);
int						check_map_validity(t_mlx *mlx, char **map);
int						replace_space(t_mlx **mlx);
void					flood_fill(char **map, t_mlx *mlx, int x, int y);
char					**create_tmp_map(char **map);
char					**ft_copy_tab(char **src, int size);
int						get_width(char **str);
int						get_maxlenght(char **str);
void					get_player_data(t_mlx *mlx, int i, int j, char c);
int						check_map(t_mlx **mlx);

// Utility functions
int						ft_error(char *error);
void					ft_printf_message(char *message);
char					*free_char(char *str);
void					free_tab(char **tab);
void					free_all(t_mlx **mlx);
void					print_banner(void);
int						ft_strlen_color(char *color);
void					process_map_character(t_mlx **mlx, bool *find_zero,
							char **tmp, t_xy *ij);

// Event handling
int						window_hook(int event, void *param);
int						keydown_keys(int key, void *params);
int						ft_close(int event, void *param);
int						mouse_hook(int button, void *param);
int						mouse_reset(int button, void *param);

// Map attribute functions
int						attribute_data_map(t_mlx *mlx);
int						attribute_color(t_mlx *mlx);
void					lst_print_data(t_map *lst);
int						check_data_map(t_data_map *data_map);
int						rgb_to_hex(char *color);
int						check_color(char *color);

// Additional calculation and checking
int						select_color(t_mlx *mlx, int x, int y);
int						check_neg_step(t_mlx *mlx, int h);
int mouse_wheel_hook(int button, void *param);


#endif