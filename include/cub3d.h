/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:40:03 by kdaumont          #+#    #+#             */
/*   Updated: 2024/04/23 12:25:29 by cornguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <math.h>

# ifndef M_PI
#  define M_PI 3.1415926
# endif

typedef struct t_window
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;			
	int				taille_x;
	int				taille_y;
	int				size_screen_x;
	int				size_screen_y;
	int				w_map;
	int				h_map;
	int				size_case;
	int				player_start_x;
	int				player_start_y;
	int				last_x_mouse;
	double			start_angle;
	double			distance;
	int				flag_wall;
	int				show_map;
	char			**map;
	char			start_orientation;
	struct s_player	*data_player;
}	t_window;


typedef struct s_player
{
	int		posx;
	int		posy;
	double	angle;
	double	fov_rad;
	double	player_speed;
	double	rotation_speed;
}	t_player;

/* utils.c */
void	error_msg(char *str);
int		close_win(t_window *data_window);
double	check_angle(double angle);
int		unit_circle(double angle, char c);

/* parsing.c */
int		is_cub_file(char *str, char *ext);

/* movement.c */
int		action_key(int keycode, t_window *data_window);
int		draw_map(t_window *data);
int		mouse_hook(int x, int y, t_window *data);

/* ray_casting */
void	ray_casting(t_window *data);

/* mini_map.c */
void	my_mlx_pixel_put(t_window *data, int x, int y, int color);
int		draw_map(t_window *data);

/* put_element.c */
void	show_wall(t_window *data, int ray);

/* init_mvt.c */
void	move_z(t_window *data);
void	move_s(t_window *data);
void	move_a(t_window *data);
void	move_d(t_window *data);

#endif
