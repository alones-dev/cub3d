/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:17:18 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/20 15:01:11 by cornguye         ###   ########.fr       */
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

	// data_window->map = malloc(sizeof(char *) * 6);
	// data_window->map[0] = "11111111";
	// data_window->map[1] = "10000001";
	// data_window->map[2] = "10000001";
	// data_window->map[3] = "11000001";
	// data_window->map[4] = "11111111";
	// data_window->map[5] = NULL;
	
	data_window->w_map = 5;
	data_window->h_map = 10;
	data_window->size_case = 30;
}

void	init_player(t_window *data_window)
{
	data_window->data_player->posx = 11;
	data_window->data_player->posy = 11;
	data_window->data_player->fov_rad = (60 * M_PI) / 180;
	data_window->data_player->angle = M_PI;
	data_window->data_player->player_speed = 3;
	data_window->data_player->rotation_speed = 0.1;
}

int	init_all(t_window *data_window)
{
	init_map(data_window);
	init_player(data_window);
	return (0);
}

double	check_angle(double angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

int	unit_circle(double angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (c == 'y')
	{
	if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
		return (1);
	}
	return (0);
}

int	inter_check(double angle, double *inter, double *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += 30;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2)) 
		{
			*inter += 30;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

int	wall_hit(double x, double y, t_window *data)
{
	int  x_m;
	int  y_m;

	if (x < 0 || y < 0)
		return (0);
	x_m = floor (x / data->size_case);
	y_m = floor (y / data->size_case);
	if ((y_m >= data->h_map || x_m >= data->w_map))	
		return (0);
	if (data->map[y_m] && x_m <= (int)ft_strlen(data->map[y_m]))
	{
		if (data->map[y_m][x_m] == '1')
			return (0);
	}
	return (1);
}

double	wall_hit_hori(t_window *data, double angle)
{
	double h_x;
	double h_y;
	double x_step;
	double y_step;
	int  pixel;

	y_step = data->size_case;
	x_step = data->size_case / tan(angle);
	h_y = floor (data->data_player->posy / data->size_case) * data->size_case;
	pixel = inter_check(angle, &h_y, &y_step, 1);
	h_x = data->data_player->posx + (h_y - data->data_player->posy) / tan(angle);
	if ((unit_circle(angle, 'y') && x_step > 0) || (!unit_circle(angle, 'y') && x_step < 0))
		x_step *= -1;
	while (wall_hit(h_x, h_y - pixel, data))
	{
		h_x += x_step;
		h_y += y_step;
	}
	return (sqrt(pow(h_x - data->data_player->posx, 2) + pow(h_y - data->data_player->posy, 2)));
}

double	wall_hit_vert(t_window *data, double angle)
{
	double	v_x;
	double	v_y;
	double	x_step;
	double	y_step;
	int		pixel;

	x_step = data->size_case;
	y_step = data->size_case * tan(angle);
	v_x = floor (data->data_player->posx / data->size_case) * data->size_case;
	pixel = inter_check(angle, &v_x, &x_step, 0);
	v_y = data->data_player->posy + (v_x - data->data_player->posx) *tan (angle);
	if ((unit_circle(angle, 'x') && y_step < 0) || (!unit_circle(angle, 'x') && y_step > 0))
		y_step *= -1;
	while (wall_hit(v_x - pixel, v_y, data))
	{
		v_x += x_step;
		v_y += y_step;
	}
	return (sqrt(pow(v_x - data->data_player->posx, 2) + pow(v_y - data->data_player->posy, 2)));
}

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

void	draw_floor_ceiling(t_window *data, int ray, int t_pix, int b_pix)
{
	int  i;

	i = b_pix;
	while (i < data->taille_y) // sol
		my_mlx_pixel_put(data, ray, i++, 0x007fd75c);
	i = 0;
	while (i < t_pix) // ciel
		my_mlx_pixel_put(data, ray, i++, 0x00007bff);
}

int	get_color(t_window *data, int flag)
{
	data->start_angle = check_angle(data->start_angle);
	if (flag == 0)
	{
		if (data->start_angle > M_PI / 2 && data->start_angle < 3 * (M_PI / 2))
			return (0xB5B5B5FF);
		else
			return (0xB5B5B5FF);
	}
	else
	{
		if (data->start_angle > 0 && data->start_angle < M_PI)
			return (0xF5F5F5FF);
		else
			return (0xF5F5F5FF);
	}
}

void	draw_wall(t_window *data, int ray, int t_pix, int b_pix)
{
	int	color;

	color = get_color(data, data->flag_wall);
	while (t_pix < b_pix)
		my_mlx_pixel_put(data, ray, t_pix++, color);
}

void	show_wall(t_window *data, int ray)
{
	double	wall_h;
	double	b_pix;
	double	t_pix;

	data->distance *= cos(check_angle(data->start_angle - data->data_player->angle));
	wall_h = (data->size_case / data->distance) * ((data->taille_x / 2) / tan(data->data_player->fov_rad / 2));
	b_pix = (data->taille_y / 2) + (wall_h / 2);
	t_pix = (data->taille_y / 2) - (wall_h / 2);
	if (b_pix > data->taille_y)
		b_pix = data->taille_y;
	if (t_pix < 0)
		t_pix = 0;
	draw_wall(data, ray, t_pix, b_pix);
	draw_floor_ceiling(data, ray, t_pix, b_pix);
}

void	ray_casting(t_window *data)
{
	double	hori_dist;
	double	vert_dist;
	int		abs;

	abs = 0;
	data->start_angle = data->data_player->angle - (data->data_player->fov_rad / 2);
	while (abs < data->taille_x)
	{
		data->flag_wall = 0;
		hori_dist = wall_hit_hori(data, check_angle(data->start_angle));
		vert_dist = wall_hit_vert(data, check_angle(data->start_angle));
		if (vert_dist < hori_dist)
			data->distance = vert_dist;
		else
		{
			data->distance = hori_dist;
			data->flag_wall = 1;
		}
		show_wall(data, abs);
		abs++;
		data->start_angle += (data->data_player->fov_rad / data->taille_x);
	}
}

int	loop(void *st)
{
	t_window	*data_window;

	data_window = st;
	mlx_destroy_image(data_window->mlx, data_window->img);
	data_window->img = mlx_new_image(data_window->mlx, data_window->taille_x, data_window->taille_y);
	data_window->addr = mlx_get_data_addr(data_window->img, &data_window->bits_per_pixel, &data_window->line_length, &data_window->endian);
	ray_casting(data_window);
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
	printf("Initial position player X:%d Y:%d\n", data_window.data_player->posx, data_window.data_player->posy);
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
