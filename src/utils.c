/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:26:39 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/29 10:36:51 by cornguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | (b));
}

int	set_start_value(t_window *data, int i, int j, t_map *map)
{
	if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
	{
		data->start_orientation = map->map[i][j];
		data->player_start_x = j;
		data->player_start_y = i;
		return (1);
	}
	else
		return (0);
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

char	*ft_strdup_stop_wspace(const char *s)
{
	int		i;
	int		len_src;
	char	*result;

	len_src = 0;
	i = 0;
	while (s[len_src] && s[len_src] != ' ' && s[len_src] != '\t'
		&& s[len_src] != '\n')
		len_src++;
	result = malloc((len_src + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
