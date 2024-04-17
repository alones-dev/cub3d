/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:17:18 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/17 10:29:35 by cornguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_win(t_print_window *data)
{
	//mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (EXIT_SUCCESS);
	return (0);
}

int	action_key(int keycode, t_print_window *data)
{
	if (keycode == 65307)
		close_win(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_print_window	data_window;
	
	if (ac != 2)
		return (error_msg("Usage : ./cub3D scene.cub"), 1);
	if (!is_cub_file(av[1], ".cub"))
		return (error_msg("Invalid file extension (.cub needed)"), 1);
	printf("File is valid -> %s\n", av[1]);
	
	data_window.mlx = mlx_init();
	//mlx_get_screen_size(data_window.mlx, &data_window.taille_x, &data_window.taille_y); // extract size of sreen
	data_window.taille_x = 800;
	data_window.taille_y = 800;
	data_window.win = mlx_new_window(data_window.mlx, data_window.taille_x, data_window.taille_y, "Bonjour je suis Bob !");

	mlx_key_hook(data_window.win, action_key, &data_window); // close with echap
	mlx_hook(data_window.win, 17, 1L << 17, close_win, &data_window); // close with cross
	mlx_loop(data_window.mlx);
	return (0);
}
