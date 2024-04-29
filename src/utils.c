/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:26:39 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/29 10:30:34 by cornguye         ###   ########.fr       */
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

/* Check if the file have the extension given
@param str -> file where the extension is checked
@param ext -> file's extension
@return :
	0 = bad extension
	1 = same extension
*/
int	is_cub_file(char *str, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(str) - ft_strlen(ext);
	j = 0;
	while (str[i])
	{
		if (str[i] != ext[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

/* Check if the character is in the set
@param c -> character to check
@param set -> set of characters
@return :
	1 = character is in the set
	0 = character is not in the set
*/
int is_in_set(char c, char *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

/* Free all values in map structure
@param map -> t_map struct pointer
*/
void	free_struct(t_map *map)
{
	if (map->map)
		free_array(map->map);
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
	if (map->f)
		free(map->f);
	if (map->c)
		free(map->c);
}

/* Check if the character is space or tab
@param c -> character to check
@return :
	1 = character is space or tab
	0 = character is not space or tab

*/
int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
		return (1);
	return (0);
}
