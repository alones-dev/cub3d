/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:40:03 by kdaumont          #+#    #+#             */
/*   Updated: 2024/04/29 09:38:04 by cornguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "get_next_line.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <stdio.h>
# include <math.h>
# include <stdint.h>

# ifndef M_PI
#  define M_PI 3.1415926
# endif

typedef struct t_window
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;			
	int					taille_x;
	int					taille_y;
	int					size_screen_x;
	int					size_screen_y;
	int					w_map;
	int					h_map;
	int					size_case;
	int					player_start_x;
	int					player_start_y;
	int					last_x_mouse;
	double				start_angle;
	double				distance;
	double				final_h_x;
	double				final_v_y;
	double				height_wall_abs;
	int					flag_wall;
	int					show_map;
	char				**map;
	char				start_orientation;
	struct s_map		*data_map;
	struct s_player		*data_player;
	struct s_texture	*texture_s;
	struct s_texture	*texture_w;
	struct s_texture	*texture_e;
	struct s_texture	*texture_n;
}	t_window;

typedef struct s_map
{
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	int		floor[3];
	int		ceiling[3];
}			t_map;

typedef struct s_texture
{
	void	*img;
	int		*addr;
	int		width;
	int		height;
	int		bit_pixel;
	int		endian;
	int		size_line;
}	t_texture;

typedef struct s_player
{
	int		posx;
	int		posy;
	double	angle;
	double	fov_rad;
	double	player_speed;
	double	rotation_speed;
}	t_player;

typedef struct s_mini_map
{
	int	compteur_x;
	int	compteur_y;
	int	size_tile_x;
	int	size_tile_y;
	int	color_player;
	int	color_path;
	int	color_wall;
}	t_mini_map;

/* utils.c */
double		check_angle(double angle);
int			unit_circle(double angle, char c);
int			get_color_rgb(int r, int g, int b);
int			set_start_value(t_window *data, int i, int j, t_map *map);
char		*ft_strdup_stop_wspace(const char *s);

/* utils2.c */
int			close_win(t_window *data_window);
void		remove_start(t_window *data_window);
void		free_struct_map(t_window *data_window);

/* movement.c */
int			action_key(int keycode, t_window *data_window);
int			draw_map(t_window *data);
int			mouse_hook(int x, int y, t_window *data);
int			key_released_map(int keycode, t_window *data);

/* ray_casting */
void		ray_casting(t_window *data);

/* mini_map.c */
void		my_mlx_pixel_put(t_window *data, int x, int y, int color);
int			draw_map(t_window *data);

/* put_element.c */
void		show_wall(t_window *data, int ray);

/* init_mvt.c */
void		move_z(t_window *data);
void		move_s(t_window *data);
void		move_a(t_window *data);
void		move_d(t_window *data);

/* init_value.c */
int			init_all_value(t_window *data_window, t_map *map);
void		init_texture(t_window *data, t_map *map);

/* init_txt.c */
void		init_txt_s(t_window *data, char *path);
void		init_txt_e(t_window *data, char *path);
void		init_txt_n(t_window *data, char *path);
void		init_txt_w(t_window *data, char *path);
t_texture	*get_txt(t_window *data);

/* utils.c */
void		error_msg(char *str);
int			is_cub_file(char *str, char *ext);
int			is_in_set(char c, char *set);
void		free_struct(t_map *map);
int			is_space(char c);

/* parsing.c */
int			init_map(t_map *map, char *file, t_window *data);

/* map.c */
void		free_array(char **array);
int			alloc_map(t_map *map, char *file);

/* check_map.c */
int			check_all(t_map *map, t_window *data);

/* colors.c */
int			get_color(int r, int g, int b);
int			parse_color_f(t_map *map);
int			parse_color_c(t_map *map);

#endif
