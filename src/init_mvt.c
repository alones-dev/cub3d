/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mvt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:18:33 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/27 16:49:33 by cornguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_window *data, double move_x, double move_y)
{
	int	map_grid_y;
	int	map_grid_x;
	int	new_x;
	int	new_y;

	new_x = roundf(data->data_player->posx + move_x);
	new_y = roundf(data->data_player->posy + move_y);
	map_grid_x = (new_x / data->size_case);
	map_grid_y = (new_y / data->size_case);
	if (data->data_map->map[map_grid_y][map_grid_x] != '1'
		&& (data->data_map->map[map_grid_y][data->data_player->posx
		/ data->size_case] != '1'
		&& data->data_map->map[data->data_player->posy
		/ data->size_case][map_grid_x] != '1'))
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
