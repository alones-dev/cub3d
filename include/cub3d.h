/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:40:03 by kdaumont          #+#    #+#             */
/*   Updated: 2024/04/17 10:06:03 by cornguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>

typedef struct s_print_window
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
    int     taille_x;
    int     taille_y;
}	t_print_window;

/* utils.c */
void	error_msg(char *str);

/* parsing.c */
int		is_cub_file(char *str, char *ext);

#endif
