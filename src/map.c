/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:51:58 by kdaumont          #+#    #+#             */
/*   Updated: 2024/04/18 22:52:47 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Free all line in map
@param map -> t_map struct pointer
*/
void	free_map(t_map *map)
{
    int	i;

    i = -1;
    if (map->map)
    {
        while (map->map[++i])
            free(map->map[i]);
        free(map->map);
    }
}