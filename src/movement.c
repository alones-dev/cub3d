/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:25:14 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/24 08:56:28 by cornguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_released_map(int keycode, t_window *data)
{
	if (keycode == 65289)
		data->show_map = 0;
	return (0);
}

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
	else if (keycode == 119)
		move_z(data_window);
	else if (keycode == 115)
		move_s(data_window);
	else if (keycode == 97)
		move_a(data_window);
	else if (keycode == 100)
		move_d(data_window);
	else if (keycode == 113 || keycode == 65361)
		rotate_q(data_window);
	else if (keycode == 101 || keycode == 65363)
		rotate_e(data_window);
	else if (keycode == 65289)
	{
		data_window->show_map = 1;
		draw_map(data_window);
	}
	return (0);
}
