/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:53:08 by kdaumont          #+#    #+#             */
/*   Updated: 2024/04/29 10:20:37 by cornguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Check if the map get only one player start
@param map -> t_map struct pointer
@return :
	1 = 1 player start
	0 = 0 or more than 1 player start
*/
int	check_elements(t_map *map, t_window *data)
{
	int	i;
	int	j;
	int	count;

	data->w_map = 0;
	i = 0;
	j = 0;
	count = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			count += set_start_value(data, i, j, map);
			if (j > data->w_map)
				data->w_map = j;
			j++;
		}
		data->h_map = i;
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}

/* Check if there is no empty line in the map
@param map -> t_map struct pointer
@return :
	1 = no empty line
	0 = empty line found
*/
int	check_spaces(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		if (map->map[i][0] == '\n' || map->map[i][0] == '\0')
			return (0);
		while (map->map[i][j] && (map->map[i][j] == ' '
				|| map->map[i][j] == '\t'))
			j++;
		if (map->map[i][j] == '\n' || map->map[i][j] == '\0')
			return (0);
		i++;
	}
	return (1);
}

/* Check if the '0' in the map are closed by '1'
@param map -> t_map struct pointer
@param i -> line of the map
@param j -> column of the map
@return :
	1 = '0' is closed by '1'
	0 = '0' is not closed by '1'
*/
int	check_edge(t_map *map, int i, int j)
{
	int	count;

	count = 0;
	while (map->map[count])
		count++;
	if (i == 0 || i == count - 1)
		return (0);
	if (j == 0 || map->map[i][j + 1] == '\0' || map->map[i][j + 1] == '\n')
		return (0);
	if (is_space(map->map[i][j - 1]) || is_space(map->map[i][j + 1])
		|| is_space(map->map[i - 1][j]) || is_space(map->map[i + 1][j]))
		return (0);
	return (1);
}

/* Check if the map is closed
@param map -> t_map struct pointer
@return :
	1 = map is closed
	0 = map is not closed
*/
int	check_wall(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '0' || is_in_set(map->map[i][j], "NSWE") == 1)
			{
				if (!check_edge(map, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/* Check everything with all functions in map
@param map -> t_map struct pointer
@return :
	1 = everything is ok
	0 = something is wrong
*/
int	check_all(t_map *map, t_window *data)
{
	if (check_elements(map, data) == 0)
		return (error_msg("Map need 1 player start"), 0);
	if (check_spaces(map) == 0)
		return (error_msg("Empty line found in map"), 0);
	if (check_wall(map) == 0)
		return (error_msg("Map is not closed"), 0);
	return (1);
}
