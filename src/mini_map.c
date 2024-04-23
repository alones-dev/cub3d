/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:03:54 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/23 12:13:46 by cornguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_window *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0)
		return ;
	else if (x >= data->taille_x)
		return ;
	if (y < 0)
		return ;
	else if (y >= data->taille_y)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_img(t_window *data, int x, int y, int size_tile)
{
	int compteur_x_tile;
	int compteur_y_tile;
	
	compteur_y_tile = 0;
	while (x < data->taille_x)
	{
		y = 0;
		compteur_x_tile = 0;
		while (y < data->taille_y)
		{
			if (x < 100 || x > data->taille_x - 100 || y < 100 || y > data->taille_y - 100)
				my_mlx_pixel_put(data, x, y, 0x009e9a9a);
			else
			{
				if (data->map[compteur_x_tile][compteur_y_tile] == ' ' || data->map[compteur_x_tile][compteur_y_tile] == '1')
					my_mlx_pixel_put(data, x, y, 0x00000000);
				else if (compteur_x_tile == data->data_player->posy / data->size_case && compteur_y_tile == data->data_player->posx / data->size_case)
					my_mlx_pixel_put(data, x, y, 0x00fcd71c);
				else if (data->map[compteur_x_tile][compteur_y_tile] == '0')
					my_mlx_pixel_put(data, x, y, 0x00007bff);
				if ((y + 100) % size_tile == 0 && compteur_x_tile < data->h_map - 1)
					compteur_x_tile++;
			}
			y++;
		}
		if (x > 100 && (x + 100) % size_tile == 0 && compteur_y_tile < data->w_map - 1)
			compteur_y_tile++;
		x++;
	}
}

int	draw_map(t_window *data)
{
	int	x;
	int	y;
	int	size_tile;

	if (data->h_map > data->w_map)
		size_tile = (data->taille_y - 200) / data->w_map; 
	else
		size_tile = (data->taille_y - 200) / data->h_map;
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->taille_x, data->taille_y);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	x = 0;
	print_img(data, x, y, size_tile);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
