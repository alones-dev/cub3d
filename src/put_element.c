/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:15:09 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/23 12:41:23 by cornguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor_ceiling(t_window *data, int ray, int t_pix, int b_pix)
{
	int  i;

	i = b_pix;
	while (i < data->taille_y)
		my_mlx_pixel_put(data, ray, i++, 0x007fd75c);
	i = 0;
	while (i < t_pix)
		my_mlx_pixel_put(data, ray, i++, 0x00007bff);
}

int	get_color(t_window *data, int flag)
{
	data->start_angle = check_angle(data->start_angle);
	if (flag == 0)
	{
		// if (data->start_angle > M_PI / 2 && data->start_angle < 3 * (M_PI / 2))
			return (0xB5B5B5FF);
	}
	else
	{
		// if (data->start_angle > 0 && data->start_angle < M_PI)
			return (0xF5F5F5FF);
	}
}

void	draw_wall(t_window *data, int ray, int t_pix, int b_pix)
{
	int	color;

	color = get_color(data, data->flag_wall);
	while (t_pix < b_pix)
		my_mlx_pixel_put(data, ray, t_pix++, color);
}

void	show_wall(t_window *data, int ray)
{
	double	wall_h;
	double	start_pix;
	double	end_pix;

	data->distance *= cos(check_angle(data->start_angle - data->data_player->angle));
	wall_h = (data->size_case / data->distance) * ((data->taille_x / 2) / tan(data->data_player->fov_rad / 2));
	start_pix = (data->taille_y / 2) + (wall_h / 2);
	end_pix = (data->taille_y / 2) - (wall_h / 2);
	if (start_pix > data->taille_y)
		start_pix = data->taille_y;
	if (end_pix < 0)
		end_pix = 0;
	draw_wall(data, ray, end_pix, start_pix);
	draw_floor_ceiling(data, ray, end_pix, start_pix);
}
