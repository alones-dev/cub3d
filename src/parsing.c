/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:37:16 by kdaumont          #+#    #+#             */
/*   Updated: 2024/04/17 16:42:30 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* TODO:
 * Check if the 6 infos (maps textures & colors) are ok
 * Check if there is a map
 * Check if the map is the last element
 * Put the infos in the structure
 * Allocate the map
 * Check if the map is closed
 * Check if the map get the right amount of elements (1 player -> N, S, E or W)
 * Check if the player is not stuck around walls
 */

/* Get and set the size of the file contains the infos in the structure,
	and allocate file array
@param map -> t_map struct pointer
@param file -> scene file .cub
@return
	1 -> success
	0 -> error
*/
int	set_map_size(t_map *map, char *file)
{
	char	*line;
	int		fd;
	int		count;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	map->size = count;
	return (free(line), close(fd), 1);
}

/* Put the file in the structure
@param map -> t_map struct pointer
@param file -> scene file .cub
*/
int	fill_file(t_map *map, char *file)
{
	int		i;
	char	*line;
	int		fd;

	map->file = ft_calloc(sizeof(char *), map->size + 1);
	if (!map->file)
		return (free(map->file), 0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	i = -1;
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (++i < map->size)
	{
		map->file[i] = line;
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	return (free(line), close(fd), 1);
}

int	parse_info(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (ft_strcmpv2(str + i, "N", 1) == 0 || ft_strcmpv2(str + i, "NO", 2) == 0)
		return (1);
	if (ft_strcmpv2(str + i, "S", 1) == 0 || ft_strcmpv2(str + i, "SO", 2) == 0)
		return (1);
	if (ft_strcmpv2(str + i, "W", 1) == 0 || ft_strcmpv2(str + i, "WE", 2) == 0)
		return (1);
	if (ft_strcmpv2(str + i, "E", 1) == 0 || ft_strcmpv2(str + i, "EA", 2) == 0)
		return (1);
	if (ft_strcmpv2(str + i, "F", 1) == 0)
		return (1);
	if (ft_strcmpv2(str + i, "C", 1) == 0)
		return (1);
	return (0);
}

int	check_infos(t_map *map)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	while (map->file[++i])
	{
		if (parse_info(map->file[i]))
			count++;
	}
	printf("count = %d\n", count);
	if (count != 6)
		return (0);
	return (1);
}

int	init_map(t_map *map, char *file)
{
	map->map = NULL;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->f = NULL;
	map->c = NULL;
	if (!set_map_size(map, file))
		return (0);
	if (!fill_file(map, file))
		return (0);
	check_infos(map);
	return (1);
}
