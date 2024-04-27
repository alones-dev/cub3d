/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:03:54 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/27 17:39:30 by cornguye         ###   ########.fr       */
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

void	print_pixel(int x, int y, t_window *data, t_mini_map *mini_map)
{
	if (data->data_map->map[mini_map->compteur_x][mini_map->compteur_y] == ' '
		|| data->data_map->map[mini_map->compteur_x]
		[mini_map->compteur_y] == '1')
		my_mlx_pixel_put(data, x, y, mini_map->color_wall);
	else if (mini_map->compteur_x == data->data_player->posy
		/ data->size_case && mini_map->compteur_y
		== data->data_player->posx / data->size_case)
		my_mlx_pixel_put(data, x, y, mini_map->color_player);
	else if (data->data_map->map[mini_map->compteur_x]
		[mini_map->compteur_y] == '0')
		my_mlx_pixel_put(data, x, y, mini_map->color_path);
	if ((y + 100) % mini_map->size_tile_y == 0
		&& mini_map->compteur_x < data->h_map - 1)
		mini_map->compteur_x++;
}

void	print_img(t_window *data, int x, int y, t_mini_map *mini_map)
{
	mini_map->compteur_y = 0;
	while (x < data->taille_x)
	{
		y = 0;
		mini_map->compteur_x = 0;
		while (y < data->taille_y)
		{
			if (x < 100 || x > data->taille_x - 100
				|| y < 100 || y > data->taille_y - 100)
				my_mlx_pixel_put(data, x, y, 0x009e9a9a);
			else
				print_pixel(x, y, data, mini_map);
			y++;
		}
		if (x > 100 && (x + 100) % mini_map->size_tile_x == 0
			&& mini_map->compteur_y < data->w_map - 1)
			mini_map->compteur_y++;
		x++;
	}
}

int	draw_map(t_window *data)
{
	int			x;
	int			y;
	t_mini_map	mini_map;

	mini_map.compteur_x = 0;
	mini_map.compteur_y = 0;
	mini_map.color_player = 0x00fcd71c;
	mini_map.color_wall = 0x00000000;
	mini_map.color_path = 0x00007bff;
	mini_map.size_tile_x = (data->taille_x - 200) / data->w_map;
	mini_map.size_tile_y = (data->taille_y - 200) / data->h_map;
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->taille_x, data->taille_y);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	x = 0;
	y = 0;
	print_img(data, x, y, &mini_map);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
