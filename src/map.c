/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:51:58 by kdaumont          #+#    #+#             */
/*   Updated: 2024/04/22 09:35:32 by kdaumont         ###   ########.fr       */
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

/* Check if the line of the map is valid
@param str -> line to check
@return :
	1 = valid
	0 = invalid
*/
int	valid_map(char *str, int state)
{
	int	i;

	if (state == 0)
	{
		i = 0;
		while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
			i++;
		if (!str[i] || str[i] == '\n')
			return (0);
	}
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
		i++;
	while (str[i])
	{
		if (!is_in_set(str[i], "01NSWE") && str[i] != ' ' && str[i] != '\n'
			&& str[i] != '\t' && str[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}

/* Parse the map in the file
@param map -> t_map struct pointer
@param file -> file to parse
@param state -> state of the parsing (0 = count, 1 = put in struct)
@return :
	-1 = error
	count = number of lines of map
*/
int	parse_map(t_map *map, char *file, int state)
{
	char	*line;
	int		fd;
	int		count;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	count = 0;
	while (line != NULL && valid_map(line, 0) == 0)
		(free(line), line = get_next_line(fd));
	while (line != NULL)
	{
		if (valid_map(line, 1) == 0)
			return (free(line), close(fd), -1);
		if (state == 1)
			map->map[count] = ft_strdup(line);
		count++;
		(free(line), line = get_next_line(fd));
	}
	if (state == 1)
		map->map[count] = NULL;
	return (free(line), close(fd), count);
}

/* Remove spaces at the end of the map
@param map -> t_map struct pointer
*/
void	remove_spaces(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
		i++;
	while (--i > 0 && (map->map[i][0] == '\n' || map->map[i][0] == '\0'))
	{
		if (map->map[i][0] == '\n' || map->map[i][0] == '\0')
			map->map[i] = NULL;
	}
}

/* Allocate memory for the map
@param map -> t_map struct pointer
@param file -> file to parse
@return :
	1 = alloc ok
	0 = alloc failed
*/
int	alloc_map(t_map *map, char *file)
{
	int	size;

	size = parse_map(map, file, 0);
	if (size == -1 || size == 0)
		return (error_msg("Map invalid"), 0);
	map->map = malloc(sizeof(char *) * (size + 1));
	if (!map->map)
		return (0);
	if (parse_map(map, file, 1) == -1)
		return (0);
	remove_spaces(map);
	return (1);
}
