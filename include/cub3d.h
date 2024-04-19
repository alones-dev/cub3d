/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:40:03 by kdaumont          #+#    #+#             */
/*   Updated: 2024/04/19 12:17:11 by cornguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <math.h>

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
	char			**map;
	struct s_player	*data_player;
}	t_window;

typedef struct s_player
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	speed;
	double	rot_speed;
	char	start_dir;
}	t_player;

/* utils.c */
void	error_msg(char *str);

/* parsing.c */
int		is_cub_file(char *str, char *ext);

#endif
