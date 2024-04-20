/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:26:39 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/20 13:35:08 by cornguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
