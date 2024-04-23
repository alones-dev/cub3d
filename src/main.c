/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:17:18 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/23 13:40:49 by cornguye         ###   ########.fr       */
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
		data_window->img = mlx_new_image(data_window->mlx, data_window->taille_x, data_window->taille_y);
		data_window->addr = mlx_get_data_addr(data_window->img, &data_window->bits_per_pixel, &data_window->line_length, &data_window->endian);
		ray_casting(data_window);
		mlx_put_image_to_window(data_window->mlx, data_window->win, data_window->img, 0, 0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_window	data_window;
	t_player	data_player;
	double		handler_size_srceen = 0.5;

	data_window.data_player = &data_player;
	data_window.map = NULL;
	if (ac != 2)
		return (error_msg("Usage : ./cub3D scene.cub"), 1);
	if (!is_cub_file(av[1], ".cub"))
		return (error_msg("Invalid file extension (.cub needed)"), 1);
	printf("File is valid -> %s\n", av[1]);

	init_all(&data_window);
	if (data_window.map[data_window.player_start_x][data_window.player_start_y] != '0')
		return (0);
	data_window.mlx = mlx_init();
	mlx_get_screen_size(data_window.mlx, &data_window.size_screen_x, &data_window.size_screen_y);
	data_window.taille_x = data_window.size_screen_x * handler_size_srceen;
	data_window.taille_y = data_window.size_screen_y * handler_size_srceen;
	data_window.win = mlx_new_window(data_window.mlx, data_window.taille_x, data_window.taille_y, "Bonjour je suis Bob !");
	data_window.img = mlx_new_image(data_window.mlx, data_window.taille_x, data_window.taille_y);
	data_window.addr = mlx_get_data_addr(data_window.img, &data_window.bits_per_pixel, &data_window.line_length, &data_window.endian);
	
	mlx_loop_hook(data_window.mlx, &loop, &data_window);
	mlx_hook(data_window.win, KeyPress, KeyPressMask, action_key, &data_window);

	mlx_key_hook(data_window.win, &key_released_map, &data_window); // Relâchement de touche tab
	mlx_hook(data_window.win, MotionNotify, PointerMotionMask, mouse_hook, &data_window);

	mlx_hook(data_window.win, 17, 1L << 17, close_win, &data_window);
	mlx_loop(data_window.mlx);
	return (0);
}
