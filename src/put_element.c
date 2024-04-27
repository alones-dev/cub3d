/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:15:09 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/26 16:02:26 by cornguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floor_ceiling(t_window *data, int ray, int start_pix, int end_pix)
{
	int	start_draw;

	start_draw = end_pix;
	while (start_draw < data->taille_y)
	{
		my_mlx_pixel_put(data, ray, start_draw, get_color_rgb(132, 251, 85));
		start_draw++;
	}
	start_draw = 0;
	while (start_draw < start_pix)
	{
		my_mlx_pixel_put(data, ray, start_draw, get_color_rgb(12, 51, 5));
		start_draw++;
	}
}

int	extract_value_tab(t_texture *texture, t_window *data)
{
	int	value;

	value = 0;
	if (data->flag_wall == 1)
		value = ((int)data->final_h_x
				* (texture->width / data->size_case)) % texture->width;
	else
		value = ((int)data->final_v_y
				* (texture->width / data->size_case)) % texture->width;
	return (value);
}

void	draw_wall(t_window *data, int abs, int start_pix, int end_pix)
{
	int			ind_tab_color;
	char		*dst;
	double		step;
	double		zoom_near_wall;
	t_texture	*texture;

	texture = get_txt(data);
	step = (double)texture->height / data->height_wall_abs;
	ind_tab_color = extract_value_tab(texture, data);
	zoom_near_wall = (start_pix - (data->taille_y / 2)
			+ (data->height_wall_abs / 2)) * step;
	if (zoom_near_wall < 0)
		zoom_near_wall = 0;
	while (start_pix < end_pix)
	{
		dst = data->addr + (start_pix * data->line_length
				+ abs * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = texture->addr[(int)zoom_near_wall
			* texture->width + ind_tab_color];
		start_pix++;
		zoom_near_wall += step;
	}
}

void	show_wall(t_window *data, int abs)
{
	double	start_pix;
	double	end_pix;

	data->distance *= cos(check_angle(data->start_angle
				- data->data_player->angle));
	data->height_wall_abs = (data->size_case / data->distance)
		* ((data->taille_x / 2) / tan(data->data_player->fov_rad / 2));
	start_pix = (data->taille_y / 2) + (data->height_wall_abs / 2);
	end_pix = (data->taille_y / 2) - (data->height_wall_abs / 2);
	if (start_pix > data->taille_y)
		start_pix = data->taille_y;
	if (end_pix < 0)
		end_pix = 0;
	draw_wall(data, abs, end_pix, start_pix);
	floor_ceiling(data, abs, end_pix, start_pix);
}
