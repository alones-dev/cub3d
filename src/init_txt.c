/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_txt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:26:32 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/26 16:01:39 by cornguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_txt_s(t_window *data, char *path)
{
	t_texture	*data_txt;

	data_txt = malloc(sizeof(t_texture) * 1);
	data_txt->img = mlx_xpm_file_to_image(data->mlx, path,
			&data_txt->width, &data_txt->height);
	data_txt->addr = (int *)mlx_get_data_addr(data_txt->img,
			&data_txt->bit_pixel, &data_txt->size_line, &data_txt->endian);
	data->texture_S = data_txt;
}

void	init_txt_e(t_window *data, char *path)
{
	t_texture	*data_txt;

	data_txt = malloc(sizeof(t_texture) * 1);
	data_txt->img = mlx_xpm_file_to_image(data->mlx, path,
			&data_txt->width, &data_txt->height);
	data_txt->addr = (int *)mlx_get_data_addr(data_txt->img,
			&data_txt->bit_pixel, &data_txt->size_line, &data_txt->endian);
	data->texture_E = data_txt;
}

void	init_txt_n(t_window *data, char *path)
{
	t_texture	*data_txt;

	data_txt = malloc(sizeof(t_texture) * 1);
	data_txt->img = mlx_xpm_file_to_image(data->mlx, path,
			&data_txt->width, &data_txt->height);
	data_txt->addr = (int *)mlx_get_data_addr(data_txt->img,
			&data_txt->bit_pixel, &data_txt->size_line, &data_txt->endian);
	data->texture_N = data_txt;
}

void	init_txt_w(t_window *data, char *path)
{
	t_texture	*data_txt;

	data_txt = malloc(sizeof(t_texture) * 1);
	data_txt->img = mlx_xpm_file_to_image(data->mlx, path,
			&data_txt->width, &data_txt->height);
	data_txt->addr = (int *)mlx_get_data_addr(data_txt->img,
			&data_txt->bit_pixel, &data_txt->size_line, &data_txt->endian);
	data->texture_W = data_txt;
}

t_texture	*get_txt(t_window *data)
{
	data->start_angle = check_angle(data->start_angle);
	if (data->flag_wall == 0)
	{
		if (data->start_angle > M_PI / 2 && data->start_angle < 3 * (M_PI / 2))
			return (data->texture_E);
		else
			return (data->texture_W);
	}
	else
	{
		if (data->start_angle > 0 && data->start_angle < M_PI)
			return (data->texture_S);
		else
			return (data->texture_N);
	}
}
