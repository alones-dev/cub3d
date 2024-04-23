/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:25:14 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/23 12:21:09 by cornguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_q(t_window *data)
{
	data->data_player->angle -= data->data_player->rotation_speed;
	if (data->data_player->angle < 0)
		data->data_player->angle += 2 * M_PI;
}

void	rotate_e(t_window *data)
{
	data->data_player->angle += data->data_player->rotation_speed;
	if (data->data_player->angle > 2 * M_PI)
		data->data_player->angle -= 2 * M_PI;
}

int	mouse_hook(int x, int y, t_window *data)
{	
	if (x < data->last_x_mouse)
	{
		data->data_player->angle -= 0.02;
		if (data->data_player->angle < 0)
			data->data_player->angle += 2 * M_PI;
	}
	else if (x > data->last_x_mouse)
	{
		data->data_player->angle += 0.02;
		if (data->data_player->angle > 2 * M_PI)
			data->data_player->angle -= 2 * M_PI;
	}
	data->last_x_mouse = x;
	return (0);
}

int	action_key(int keycode, t_window *data_window)
{
	if (keycode == 65307)
		close_win(data_window);
	else if (keycode == 119)	// z
		move_z(data_window);
	else if (keycode == 115)	// s
		move_s(data_window);
	else if (keycode == 97)		// a
		move_a(data_window);
	else if (keycode == 100)	// d
		move_d(data_window);
	else if (keycode == 113 || keycode == 65361)	// rotate left
		rotate_q(data_window);
	else if (keycode == 101 || keycode == 65363)	// rotate right
		rotate_e(data_window);
	else if (keycode == 65289)
	{
		data_window->show_map = 1;
		draw_map(data_window);
	}
	return (0);
}
