/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:59:40 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/23 12:25:17 by cornguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	inter_check(double angle, double *inter, double *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += 30;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2)) 
		{
			*inter += 30;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

int	wall_hit(double x, double y, t_window *data)
{
	int  x_m;
	int  y_m;

	if (x < 0 || y < 0)
		return (0);
	x_m = floor (x / data->size_case);
	y_m = floor (y / data->size_case);
	if ((y_m >= data->h_map || x_m >= data->w_map))	
		return (0);
	if (data->map[y_m] && x_m <= (int)ft_strlen(data->map[y_m]))
	{
		if (data->map[y_m][x_m] == '1')
			return (0);
	}
	return (1);
}

double	wall_hit_hori(t_window *data, double angle)
{
	double h_x;
	double h_y;
	double x_step;
	double y_step;
	int  pixel;

	y_step = data->size_case;
	x_step = data->size_case / tan(angle);
	h_y = floor (data->data_player->posy / data->size_case) * data->size_case;
	pixel = inter_check(angle, &h_y, &y_step, 1);
	h_x = data->data_player->posx + (h_y - data->data_player->posy) / tan(angle);
	if ((unit_circle(angle, 'y') && x_step > 0) || (!unit_circle(angle, 'y') && x_step < 0))
		x_step *= -1;
	while (wall_hit(h_x, h_y - pixel, data))
	{
		h_x += x_step;
		h_y += y_step;
	}
	return (sqrt(pow(h_x - data->data_player->posx, 2) + pow(h_y - data->data_player->posy, 2)));
}

double	wall_hit_vert(t_window *data, double angle)
{
	double	v_x;
	double	v_y;
	double	x_step;
	double	y_step;
	int		pixel;

	x_step = data->size_case;
	y_step = data->size_case * tan(angle);
	v_x = floor (data->data_player->posx / data->size_case) * data->size_case;
	pixel = inter_check(angle, &v_x, &x_step, 0);
	v_y = data->data_player->posy + (v_x - data->data_player->posx) *tan (angle);
	if ((unit_circle(angle, 'x') && y_step < 0) || (!unit_circle(angle, 'x') && y_step > 0))
		y_step *= -1;
	while (wall_hit(v_x - pixel, v_y, data))
	{
		v_x += x_step;
		v_y += y_step;
	}
	return (sqrt(pow(v_x - data->data_player->posx, 2) + pow(v_y - data->data_player->posy, 2)));
}

void	ray_casting(t_window *data)
{
	double	hori_dist;
	double	vert_dist;
	int		abs;

	abs = 0;
	data->start_angle = data->data_player->angle - (data->data_player->fov_rad / 2);
	while (abs < data->taille_x)
	{
		data->flag_wall = 0;
		hori_dist = wall_hit_hori(data, check_angle(data->start_angle));
		vert_dist = wall_hit_vert(data, check_angle(data->start_angle));
		if (vert_dist < hori_dist)
			data->distance = vert_dist;
		else
		{
			data->distance = hori_dist;
			data->flag_wall = 1;
		}
		show_wall(data, abs);
		abs++;
		data->start_angle += (data->data_player->fov_rad / data->taille_x);
	}
}
