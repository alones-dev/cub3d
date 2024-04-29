/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_txt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:26:32 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/29 09:50:25 by cornguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_txt_s(t_window *data, char *path)
{
	t_texture	*data_txt;

	data_txt = malloc(sizeof(t_texture));
	data_txt->img = mlx_xpm_file_to_image(data->mlx, path,
			&data_txt->width, &data_txt->height);
	if (data_txt->img == NULL)
	{
		free_struct_map(data);
		free(data_txt);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_putstr_fd("Error\nInvalid path to texture\n", 1);
		exit(0);
	}
	data_txt->addr = (int *)mlx_get_data_addr(data_txt->img,
			&data_txt->bit_pixel, &data_txt->size_line, &data_txt->endian);
	data->texture_s = data_txt;
}

void	init_txt_e(t_window *data, char *path)
{
	t_texture	*data_txt;

	data_txt = malloc(sizeof(t_texture));
	data_txt->img = mlx_xpm_file_to_image(data->mlx, path,
			&data_txt->width, &data_txt->height);
	if (data_txt->img == NULL)
	{
		mlx_destroy_image(data->mlx, data->texture_s->img);
		free(data->texture_s);
		free_struct_map(data);
		free(data_txt);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_putstr_fd("Error\nInvalid path to texture\n", 1);
		exit(0);
	}
	data_txt->addr = (int *)mlx_get_data_addr(data_txt->img,
			&data_txt->bit_pixel, &data_txt->size_line, &data_txt->endian);
	data->texture_e = data_txt;
}

void	init_txt_n(t_window *data, char *path)
{
	t_texture	*data_txt;

	data_txt = malloc(sizeof(t_texture));
	data_txt->img = mlx_xpm_file_to_image(data->mlx, path,
			&data_txt->width, &data_txt->height);
	if (data_txt->img == NULL)
	{
		mlx_destroy_image(data->mlx, data->texture_s->img);
		mlx_destroy_image(data->mlx, data->texture_e->img);
		free(data->texture_s);
		free(data->texture_e);
		free_struct_map(data);
		free(data_txt);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_putstr_fd("Error\nInvalid path to texture\n", 1);
		exit(0);
	}
	data_txt->addr = (int *)mlx_get_data_addr(data_txt->img,
			&data_txt->bit_pixel, &data_txt->size_line, &data_txt->endian);
	data->texture_n = data_txt;
}

void	init_txt_w(t_window *data, char *path)
{
	t_texture	*data_txt;

	data_txt = malloc(sizeof(t_texture));
	data_txt->img = mlx_xpm_file_to_image(data->mlx, path,
			&data_txt->width, &data_txt->height);
	if (data_txt->img == NULL)
	{
		mlx_destroy_image(data->mlx, data->texture_s->img);
		mlx_destroy_image(data->mlx, data->texture_e->img);
		mlx_destroy_image(data->mlx, data->texture_n->img);
		free(data->texture_s);
		free(data->texture_e);
		free(data->texture_n);
		free_struct_map(data);
		free(data_txt);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_putstr_fd("Error\nInvalid path to texture\n", 1);
		exit(0);
	}
	data_txt->addr = (int *)mlx_get_data_addr(data_txt->img,
			&data_txt->bit_pixel, &data_txt->size_line, &data_txt->endian);
	data->texture_w = data_txt;
}

t_texture	*get_txt(t_window *data)
{
	data->start_angle = check_angle(data->start_angle);
	if (data->flag_wall == 0)
	{
		if (data->start_angle > M_PI / 2 && data->start_angle < 3 * (M_PI / 2))
			return (data->texture_e);
		else
			return (data->texture_w);
	}
	else
	{
		if (data->start_angle > 0 && data->start_angle < M_PI)
			return (data->texture_s);
		else
			return (data->texture_n);
	}
}
