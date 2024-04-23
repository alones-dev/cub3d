/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:42:30 by kdaumont          #+#    #+#             */
/*   Updated: 2024/04/23 14:27:56 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Get RGB color in hex
@param r -> red value
@param g -> green value
@param b -> blue value
@return color in hex
*/
int	get_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | (b));
}

/* Get the length of the array
@param tab -> array to check
@return length of the array
*/
int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

/* Parse the color of the floor
@param map -> t_map struct pointer
@return :
	1 = success
	0 = error
*/
int	parse_color_f(t_map *map)
{
	char	**split;
	char	*tmp;
	int		i;

	split = ft_split(map->f, ',');
	if (!split)
		return (0);
	if (ft_tablen(split) != 3)
		return (free_array(split), 0);
	i = 0;
	while (split[i])
	{
		if (i == 2)
			split[i][ft_strlen(split[i]) - 1] = '\0';
		tmp = ft_itoa(ft_atoi(split[i]));
		if (!tmp)
			return (free_array(split), 0);
		if (ft_strncmp(tmp, split[i]) != 0)
			return (free_array(split), free(tmp), 0);
		if (ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255)
			return (free_array(split), free(tmp), 0);
		map->floor[i] = ft_atoi(split[i]);
		(free(tmp), i++);
	}
	return (free_array(split), 1);
}

/* Parse the color of the ceiling
@param map -> t_map struct pointer
@return :
	1 = success
	0 = error
*/
int	parse_color_c(t_map *map)
{
	char	**split;
	char	*tmp;
	int		i;

	split = ft_split(map->c, ',');
	if (!split)
		return (0);
	if (ft_tablen(split) != 3)
		return (free_array(split), 0);
	i = 0;
	while (split[i])
	{
		if (i == 2)
			split[i][ft_strlen(split[i]) - 1] = '\0';
		tmp = ft_itoa(ft_atoi(split[i]));
		if (!tmp)
			return (free_array(split), 0);
		if (ft_strncmp(tmp, split[i]) != 0)
			return (free_array(split), free(tmp), 0);
		if (ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255)
			return (free_array(split), free(tmp), 0);
		map->ceiling[i] = ft_atoi(split[i]);
		(free(tmp), i++);
	}
	return (free_array(split), 1);
}
