/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:17:18 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/29 08:58:50 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop(void *st)
{
	t_window	*data_window;

	data_window = st;
	if (data_window->show_map)
		draw_map(data_window);
	else
	{
		mlx_destroy_image(data_window->mlx, data_window->img);
		data_window->img = mlx_new_image(data_window->mlx,
				data_window->taille_x, data_window->taille_y);
		data_window->addr = mlx_get_data_addr(data_window->img,
				&data_window->bits_per_pixel, &data_window->line_length,
				&data_window->endian);
		ray_casting(data_window);
		mlx_put_image_to_window(data_window->mlx, data_window->win,
			data_window->img, 0, 0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_window	data_window;
	t_player	data_player;
	t_map		map;

	data_window.data_player = &data_player;
	data_window.map = NULL;
	if (ac != 2)
		return (error_msg("Usage : ./cub3D scene.cub"), 1);
	if (!is_cub_file(av[1], ".cub"))
		return (error_msg("Invalid file extension (.cub needed)"), 1);
	if (!init_map(&map, av[1], &data_window))
		return (free_struct(&map), 1);
	init_all_value(&data_window, &map);
	remove_start(&data_window);
	mlx_loop_hook(data_window.mlx, &loop, &data_window);
	mlx_hook(data_window.win, KeyPress, KeyPressMask, action_key, &data_window);
	mlx_key_hook(data_window.win, &key_released_map, &data_window);
	mlx_hook(data_window.win, MotionNotify, PointerMotionMask, mouse_hook,
		&data_window);
	mlx_hook(data_window.win, 17, 1L << 17, close_win, &data_window);
	mlx_loop(data_window.mlx);
	return (0);
}
