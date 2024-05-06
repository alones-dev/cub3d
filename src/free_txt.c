/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_txt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:25:25 by cornguye          #+#    #+#             */
/*   Updated: 2024/05/06 09:26:19 by cornguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_txt_1(t_window *data, t_texture *data_txt)
{
	free_struct_map(data);
	free(data_txt);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_putstr_fd("Error\nInvalid path to texture\n", 1);
	exit(0);
}

void	free_txt_2(t_window *data, t_texture *data_txt)
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

void	free_txt_3(t_window *data, t_texture *data_txt)
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

void	free_txt_4(t_window *data, t_texture *data_txt)
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
