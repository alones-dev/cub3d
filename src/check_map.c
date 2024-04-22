/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:53:08 by kdaumont          #+#    #+#             */
/*   Updated: 2024/04/22 09:37:20 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Check if the map get only one player start
@param map -> t_map struct pointer
@return :
	1 = 1 player start
	0 = 0 or more than 1 player start
*/
int	check_elements(t_map *map)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
				count++;
			j++;
		}
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
		while (map->map[i][j] && (map->map[i][j] == ' ' || map->map[i][j] == '\t'))
			j++;
		if (map->map[i][j] == '\n' || map->map[i][j] == '\0')
			return (0);
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
int	check_all(t_map *map)
{
	if (check_elements(map) == 0)
		return (error_msg("Map need 1 player start"), 0);
	if (check_spaces(map) == 0)
		return (error_msg("Empty line found in map"), 0);
	return (1);
}
