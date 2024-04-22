/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:40:03 by kdaumont          #+#    #+#             */
/*   Updated: 2024/04/22 09:41:43 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	int		first_map;
	int		last_info;
	int		i;
}			t_map;

/* utils.c */
void		error_msg(char *str);
int			is_cub_file(char *str, char *ext);
int			is_in_set(char c, char *set);
void		free_struct(t_map *map);

/* parsing.c */
int			init_map(t_map *map, char *file);

/* map.c */
void		free_map(t_map *map);
int			alloc_map(t_map *map, char *file);

/* check_map.c */
int			check_all(t_map *map);

#endif
