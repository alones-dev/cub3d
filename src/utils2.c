/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:30:50 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/27 17:53:19 by cornguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_double_tab(char **str)
{
	int	i = 0;
	
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	close_win(t_window *data_window)
{
	free_double_tab(data_window->data_map->map);
	free(data_window->data_map->ea);
	free(data_window->data_map->we);
	free(data_window->data_map->no);
	free(data_window->data_map->so);
	free(data_window->data_map->c);
	free(data_window->data_map->f);
	mlx_destroy_image(data_window->mlx, data_window->texture_s->img);
	mlx_destroy_image(data_window->mlx, data_window->texture_n->img);
	mlx_destroy_image(data_window->mlx, data_window->texture_e->img);
	mlx_destroy_image(data_window->mlx, data_window->texture_w->img);
	free(data_window->texture_e);
	free(data_window->texture_w);
	free(data_window->texture_n);
	free(data_window->texture_s);
	mlx_destroy_image(data_window->mlx, data_window->img);
	mlx_destroy_window(data_window->mlx, data_window->win);
	mlx_destroy_display(data_window->mlx);
	free(data_window->mlx);
	exit (EXIT_SUCCESS);
	return (0);
}

void	remove_start(t_window *data_window)
{
	int	i;
	int	j;

	i = 0;
	while (data_window->data_map->map[i])
	{
		j = 0;
		while (data_window->data_map->map[i][j])
		{
			if (data_window->data_map->map[i][j] == 'N'
					|| data_window->data_map->map[i][j] == 'S'
					|| data_window->data_map->map[i][j] == 'W'
					|| data_window->data_map->map[i][j] == 'E')
				data_window->data_map->map[i][j] = '0';
			j++;
		}
		i++;
	}
}
