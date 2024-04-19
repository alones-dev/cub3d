/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:53:08 by kdaumont          #+#    #+#             */
/*   Updated: 2024/04/19 15:06:51 by kdaumont         ###   ########.fr       */
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

