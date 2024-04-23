/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:26:39 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/23 13:25:47 by cornguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color_rgb(int r, int g, int b)
{
    return ((r << 16) | (g << 8) | (b));
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

double	check_angle(double angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void	error_msg(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
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
