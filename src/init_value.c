/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:36:48 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/29 10:54:06 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_value_window(t_window *data_window)
{
	data_window->h_map++;
	data_window->size_case = 32;
	data_window->show_map = 0;
}

void	init_player(t_window *data_window)
{
	if (data_window->start_orientation == 'N')
		data_window->data_player->angle = M_PI + 1.5707963;
	else if (data_window->start_orientation == 'E')
		data_window->data_player->angle = M_PI + 3.1415926;
	else if (data_window->start_orientation == 'S')
		data_window->data_player->angle = M_PI + 4.7123889;
	else if (data_window->start_orientation == 'W')
		data_window->data_player->angle = M_PI;
	data_window->data_player->posx = data_window->player_start_x
		* data_window->size_case + data_window->size_case / 2;
	data_window->data_player->posy = data_window->player_start_y
		* data_window->size_case + data_window->size_case / 2;
	data_window->data_player->fov_rad = (60 * M_PI) / 180;
	data_window->data_player->player_speed = 3;
	data_window->data_player->rotation_speed = 0.1;
}

void	init_texture(t_window *data, t_map *map)
{
	init_txt_s(data, map->so);
	init_txt_e(data, map->ea);
	init_txt_n(data, map->no);
	init_txt_w(data, map->we);
}

void	init_window(t_window *data_window)
{
	double		handler_size_srceen;

	handler_size_srceen = 0.5;
	data_window->mlx = mlx_init();
	if (data_window->mlx == NULL)
	{
		free_struct_map(data_window);
		ft_putstr_fd("Error\nmlx_init failed\n", 1);
		exit(0);
	}
	init_texture(data_window, data_window->data_map);
	mlx_get_screen_size(data_window->mlx, &data_window->size_screen_x,
		&data_window->size_screen_y);
	data_window->taille_x = data_window->size_screen_x * handler_size_srceen;
	data_window->taille_y = data_window->size_screen_y * handler_size_srceen;
	data_window->win = mlx_new_window(data_window->mlx, data_window->taille_x,
			data_window->taille_y, "cub3d");
	data_window->img = mlx_new_image(data_window->mlx, data_window->taille_x,
			data_window->taille_y);
	data_window->addr = mlx_get_data_addr(data_window->img,
			&data_window->bits_per_pixel, &data_window->line_length,
			&data_window->endian);
	data_window->last_x_mouse = data_window->taille_x / 2;
}

int	init_all_value(t_window *data_window, t_map *map)
{
	init_value_window(data_window);
	init_player(data_window);
	data_window->data_map = map;
	init_window(data_window);
	return (0);
}
