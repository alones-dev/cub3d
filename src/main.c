/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:17:18 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/23 12:04:14 by cornguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_window *data_window)
{
	data_window->map = malloc(sizeof(char *) * 16);
	data_window->map[0]  = "        1111111111111111111111111";
	data_window->map[1]  = "        1000000000110000000000001";
	data_window->map[2]  = "        1011000001110000000000001";
	data_window->map[3]  = "        1001000000000000000000001";
	data_window->map[4]  = "111111111011000001110000000000001";
	data_window->map[5]  = "100000000011000001110111111111111";
	data_window->map[6]  = "11110111111111011100000010001    ";
	data_window->map[7]  = "11110111111111011101010010001    ";
	data_window->map[8]  = "11000000110101011100000010001    ";
	data_window->map[9]  = "10000000000000001100000010001    ";
	data_window->map[10] = "10000000000000001100000010001    ";
	data_window->map[11] = "10000000000000001101010010001    ";
	data_window->map[12] = "11000001110101011111011110N0111  ";
	data_window->map[13] = "11110111 1110101 101111010001    ";
	data_window->map[14] = "11111111 1111111 111111111111    ";
	data_window->map[15] = NULL;
	
	data_window->w_map = 33;
	data_window->h_map = 15;
	data_window->size_case = 30;
	data_window->player_start_x = 10;
	data_window->player_start_y = 10;
	data_window->show_map = 0;
	data_window->last_x_mouse = data_window->taille_x / 2;
	data_window->start_orientation = 'W';
}

void	init_player(t_window *data_window)
{
	if (data_window->start_orientation == 'N')
		data_window->data_player->angle = M_PI + 1.5707963;
	else if (data_window->start_orientation == 'E')
		data_window->data_player->angle = M_PI + 3.1415926;
	else if (data_window->start_orientation == 'S')
		data_window->data_player->angle = M_PI + 4.7123889;
	else if (data_window->start_orientation == 'W')
		data_window->data_player->angle = M_PI;
	data_window->data_player->posx = data_window->player_start_x *
		data_window->size_case + data_window->size_case / 2;
	data_window->data_player->posy = data_window->player_start_y *
		data_window->size_case + data_window->size_case / 2;
	data_window->data_player->fov_rad = (60 * M_PI) / 180;
	data_window->data_player->player_speed = 3;
	data_window->data_player->rotation_speed = 0.1;
}

int	init_all(t_window *data_window)
{
	init_map(data_window);
	init_player(data_window);
	return (0);
}

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

int	key_released_map(int keycode, t_window *data)
{
	if (keycode == 65289)
		data->show_map = 0;
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
