/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:36:48 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/27 13:27:07 by cornguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_window *data_window)
{
	data_window->map = malloc(sizeof(char *) * 16);
	data_window->map[0]  = "        1111111111111111111111111";
	data_window->map[1]  = "        1000000000110000000000001";
	data_window->map[2]  = "        1011000001110000000000001";
	data_window->map[3]  = "        1001000000000000000000001";
	data_window->map[4]  = "111111111011000001110000000000001";
	data_window->map[5]  = "100000000011000001110111111111111";
	data_window->map[6]  = "11110111111111011100000010001";
	data_window->map[7]  = "11110111111111011101010010001";
	data_window->map[8]  = "11000000110101011100000010001";
	data_window->map[9]  = "10000000000000001100000010001";
	data_window->map[10] = "10000000000000001100000010001";
	data_window->map[11] = "10000000000000001101010010001";
	data_window->map[12] = "11000001110101011111011110N0111";
	data_window->map[13] = "11110111 1110101 101111010001";
	data_window->map[14] = "11111111 1111111 111111111111";
	data_window->map[15] = NULL;

	data_window->w_map = 33;
	data_window->h_map = 15;
	data_window->player_start_x = 10;
	data_window->player_start_y = 10;
	data_window->size_case = 32;
	data_window->show_map = 0;
	data_window->last_x_mouse = data_window->taille_x / 2;
	data_window->start_orientation = 'S';
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

void	init_txt(t_window *data)
{
	init_txt_s(data, "texture/test-resized.xpm");
	init_txt_e(data, "texture/m2-resized-64.xpm");
	init_txt_n(data, "texture/m3-resized-64.xpm");
	init_txt_w(data, "texture/m4-resized-64.xpm");
}

int	init_all_value(t_window *data_window)
{
	t_texture	*txt;

	init_map(data_window);
	init_player(data_window);
	return (0);
}
