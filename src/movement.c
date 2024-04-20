/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:25:14 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/20 14:23:18 by cornguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void move_player(t_window *data, double move_x, double move_y)
{
	int	map_grid_y;
	int	map_grid_x;
	int	new_x;
	int	new_y;

	new_x = roundf(data->data_player->posx + move_x);
	new_y = roundf(data->data_player->posy + move_y);
	map_grid_x = (new_x / data->size_case);
	map_grid_y = (new_y / data->size_case);
	if (data->map[map_grid_y][map_grid_x] != '1' && (data->map[map_grid_y][data->data_player->posx / data->size_case] != '1' && data->map[data->data_player->posy / data->size_case][map_grid_x] != '1'))
	{
		data->data_player->posx = new_x;
		data->data_player->posy = new_y;
	}
}

void	move_z(t_window *data)
{
	double	move_x;
	double	move_y;

	move_x = cos(data->data_player->angle) * data->data_player->player_speed;
	move_y = sin(data->data_player->angle) * data->data_player->player_speed;
	move_player(data, move_x, move_y);
}

void	move_s(t_window *data)
{
	double	move_x;
	double	move_y;

	move_x = -cos(data->data_player->angle) * data->data_player->player_speed;
  	move_y = -sin(data->data_player->angle) * data->data_player->player_speed;
	move_player(data, move_x, move_y);
}

void	move_a(t_window *data)
{
	double	move_x;
	double	move_y;

	move_x = sin(data->data_player->angle) * data->data_player->player_speed;
  	move_y = -cos(data->data_player->angle) * data->data_player->player_speed;
	move_player(data, move_x, move_y);
}

void	move_d(t_window *data)
{
	double	move_x;
	double	move_y;

	move_x = -sin(data->data_player->angle) * data->data_player->player_speed;
	move_y = cos(data->data_player->angle) * data->data_player->player_speed;
	move_player(data, move_x, move_y);
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

int	action_key(int keycode, t_window *data_window)
{
	if (keycode == 65307)
		close_win(data_window);
	else if (keycode == 119)	// z
	{
		move_z(data_window);
		printf("MOVE Z\n");
	}
	else if (keycode == 115)	// s
	{
		move_s(data_window);
		printf("MOVE S\n");
	}
	else if (keycode == 97)		// a
	{
		move_a(data_window);
		printf("MOVE A\n");
	}
	else if (keycode == 100)	// d
	{
		move_d(data_window);
		printf("MOVE D\n");
	}
	else if (keycode == 113)	// q rotate
	{
		rotate_q(data_window);
		printf("MOVE Q\n");
	}
	else if (keycode == 101)	// e rotate
	{
		rotate_e(data_window);
		printf("MOVE E\n");
	}
	return (0);
}
