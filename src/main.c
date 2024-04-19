/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:17:18 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/19 13:37:09 by cornguye         ###   ########.fr       */
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
}

void	init_player(t_window *data_window)
{
	data_window->data_player->posx = 11.0;
	data_window->data_player->posy = 10.0;
	data_window->data_player->start_dir = 'N';
	data_window->data_player->dirx = 0;
	data_window->data_player->diry = 1;
	data_window->data_player->planex = 0;
	data_window->data_player->planey = 0.66;
	data_window->data_player->speed = 0.2;
	data_window->data_player->rot_speed = 0.1;
}

int	close_win(t_window *data_window)
{
	free(data_window->map);
	mlx_destroy_image(data_window->mlx, data_window->img);
	mlx_destroy_window(data_window->mlx, data_window->win);
	mlx_destroy_display(data_window->mlx);
	free(data_window->mlx);
	exit (EXIT_SUCCESS);
	return (0);
}

int	init_all(t_window *data_window)
{
	init_map(data_window);
	init_player(data_window);
	return (0);
}

int	action_key(int keycode, t_window *data_window)
{
	if (keycode == 65307)
		close_win(data_window);
	else if (keycode == 119)	// z
	{
		if (data_window->map[(int)(data_window->data_player->posx + data_window->data_player->dirx * data_window->data_player->speed)]
			[(int)data_window->data_player->posy] == '0')
		{
			data_window->data_player->posx += data_window->data_player->dirx * data_window->data_player->speed;
		}
		if (data_window->map[(int)data_window->data_player->posx]
			[(int)(data_window->data_player->posy + data_window->data_player->diry * data_window->data_player->speed)] == '0')
		{
			data_window->data_player->posy += data_window->data_player->diry * data_window->data_player->speed;
		}
		printf("MOVE Z posx %f posy %f\n", data_window->data_player->posx, data_window->data_player->posy);
	}
	else if (keycode == 115)	// s
	{
		if (data_window->map[(int)(data_window->data_player->posx - data_window->data_player->dirx * data_window->data_player->speed)]
			[(int)data_window->data_player->posy] == '0')
		{
			data_window->data_player->posx -= data_window->data_player->dirx * data_window->data_player->speed;
		}
		if (data_window->map[(int)data_window->data_player->posx]
			[(int)(data_window->data_player->posy - data_window->data_player->diry * data_window->data_player->speed)] == '0')
		{
			data_window->data_player->posy -= data_window->data_player->diry * data_window->data_player->speed;
		}
		printf("MOVE S posx %f posy %f\n", data_window->data_player->posx, data_window->data_player->posy);
	}
	else if (keycode == 97)		// a
	{
		double	temp_dirx;
		double	temp_planex;
		temp_dirx = data_window->data_player->dirx;
		temp_planex = data_window->data_player->planex;
		data_window->data_player->dirx = data_window->data_player->dirx * cos(data_window->data_player->rot_speed) - data_window->data_player->diry * sin(data_window->data_player->rot_speed);
		data_window->data_player->diry = temp_dirx * sin(data_window->data_player->rot_speed) + data_window->data_player->diry * cos(data_window->data_player->rot_speed);
		data_window->data_player->planex = data_window->data_player->planex * cos(data_window->data_player->rot_speed) - data_window->data_player->planey * sin(data_window->data_player->rot_speed);
		data_window->data_player->planey = temp_planex * sin(data_window->data_player->rot_speed) + data_window->data_player->planey * cos(data_window->data_player->rot_speed);
		printf("MOVE A posx %f posy %f\n", data_window->data_player->posx, data_window->data_player->posy);
	}
	else if (keycode == 100)	// d
	{
		double	temp_dirx;
		double	temp_planex;
		temp_dirx = data_window->data_player->dirx;
		temp_planex = data_window->data_player->planex;
		data_window->data_player->dirx = data_window->data_player->dirx * cos(-data_window->data_player->rot_speed) - data_window->data_player->diry * sin(-data_window->data_player->rot_speed);
		data_window->data_player->diry = temp_dirx * sin(-data_window->data_player->rot_speed) + data_window->data_player->diry * cos(-data_window->data_player->rot_speed);
		data_window->data_player->planex = data_window->data_player->planex * cos(-data_window->data_player->rot_speed) - data_window->data_player->planey * sin(-data_window->data_player->rot_speed);
		data_window->data_player->planey = temp_planex * sin(-data_window->data_player->rot_speed) + data_window->data_player->planey * cos(-data_window->data_player->rot_speed);
		printf("MOVE D posx %f posy %f\n", data_window->data_player->posx, data_window->data_player->posy);
	}
	return (0);
}

void	my_mlx_pixel_put(t_window *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_pixel(t_window *data, int x, int y, int abs)
{
	int	compteur;

	if (x < 0)
		x = 0;
 	else if (x >= data->taille_x)
 		x = data->taille_x;
	if (y < 0)
  		y = 0;
 	else if (y >= data->taille_y)
 		y = data->taille_y;
	compteur = 0;
	while (compteur < data->taille_y)
	{
		if (compteur < x && compteur > y)
			my_mlx_pixel_put(data, abs, compteur, 0x00fe961f);
		else if (compteur > x)
			my_mlx_pixel_put(data, abs, compteur, 0x00FFFFFF);
		else if (compteur < y)
			my_mlx_pixel_put(data, abs, compteur, 0x004a2485);
		else
			my_mlx_pixel_put(data, abs, compteur, 0x00000000);
		compteur++;
	}
}

int	loop(void *st)
{
	t_window	*data_window;

	data_window = st;
	mlx_destroy_image(data_window->mlx, data_window->img);
	data_window->img = mlx_new_image(data_window->mlx, data_window->taille_x, data_window->taille_y);
	data_window->addr = mlx_get_data_addr(data_window->img, &data_window->bits_per_pixel, &data_window->line_length, &data_window->endian);
	int		abs;
	double	camerax;
	double	raydirx;
	double	raydiry;

	// position du perso
	int		mapx;
	int		mapy;

	double	sidedistx;
	double	sidedisty;

	double	deltadistx;
	double	deltadisty;

	int		wall_hit;
	wall_hit = 0;
	int		side;
	
	abs = 0;
	while (abs < data_window->taille_x)
	{
		camerax = 2 * abs / (double)data_window->taille_x - 1;
		raydirx = data_window->data_player->dirx + data_window->data_player->planex * camerax;
		raydiry = data_window->data_player->diry + data_window->data_player->planey * camerax;

		mapx = data_window->data_player->posx;
		mapy = data_window->data_player->posy;
	
		if (raydirx == 0)
			deltadistx = 1e30;
		else
			deltadistx = fabs(1 / raydirx);
		if (raydiry == 0)
			deltadisty = 1e30;
		else
			deltadisty = fabs(1 / raydiry);
		int	stepx;
		int	stepy;
		if (raydirx < 0)
		{
			stepx = -1;
			sidedistx = (data_window->data_player->posx - mapx) * deltadistx;
		}
		else
		{
			stepx = 1;
			sidedistx = (mapx + 1 - data_window->data_player->posx) * deltadistx;
		}
		if (raydiry < 0)
		{
			stepy = -1;
			sidedisty = (data_window->data_player->posy - mapy) * deltadisty;
		}
		else
		{
			stepy = 1;
			sidedisty = (mapy + 1 - data_window->data_player->posy) * deltadisty;
		}
		while (wall_hit == 0)
		{
			if (sidedistx < sidedisty)
			{
				sidedistx += deltadistx;
				mapx += stepx;
				side = 0;
			}
			else
			{
				sidedisty += deltadisty;
				mapy += stepy;
				side = 1;
			}
			if (data_window->map[mapx][mapy] != 0)
				wall_hit = 1;
		}
		double	wall_dist;
		if (side == 0)
			wall_dist = sidedistx - deltadistx;
		else
			wall_dist = sidedisty - deltadisty;
		int	height_wall;
		int	start_draw;
		int	end_draw;
			
		height_wall = (int)(data_window->taille_y / wall_dist);
		start_draw = -height_wall / 2 + data_window->taille_y / 2;
		end_draw = height_wall / 2 + data_window->taille_y / 2;
		put_pixel(data_window, start_draw, end_draw, abs);
		abs++;
	}
	// printf("PRINT IMG\n");
	mlx_put_image_to_window(data_window->mlx, data_window->win, data_window->img, 0, 0);
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
	printf("Initial position player X:%f Y:%f\n", data_window.data_player->posx, data_window.data_player->posy);
	if (data_window.map[(int)data_window.data_player->posx][(int)data_window.data_player->posy] != '0')
	{
		printf("ERREUR %c\n", data_window.map[(int)data_window.data_player->posx][(int)data_window.data_player->posy]);
		return (0);
	}
	data_window.mlx = mlx_init();
	mlx_get_screen_size(data_window.mlx, &data_window.size_screen_x, &data_window.size_screen_y); // extract size of srceen
	data_window.taille_x = data_window.size_screen_x * handler_size_srceen;
	data_window.taille_y = data_window.size_screen_y * handler_size_srceen;
	data_window.win = mlx_new_window(data_window.mlx, data_window.taille_x, data_window.taille_y, "Bonjour je suis Bob !");
	data_window.img = mlx_new_image(data_window.mlx, data_window.taille_x, data_window.taille_y);
	data_window.addr = mlx_get_data_addr(data_window.img, &data_window.bits_per_pixel, &data_window.line_length, &data_window.endian);
			
	mlx_loop_hook(data_window.mlx, &loop, &data_window);
	mlx_key_hook(data_window.win, action_key, &data_window); // close with echap
	mlx_hook(data_window.win, 17, 1L << 17, close_win, &data_window); // close with cross
	mlx_loop(data_window.mlx);
	return (0);
}
