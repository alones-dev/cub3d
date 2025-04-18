/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cornguye <cornguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:37:16 by kdaumont          #+#    #+#             */
/*   Updated: 2024/04/29 10:30:26 by cornguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Put the differents informations in the structure
@param map -> t_map struct pointer
@param str -> line to parse
@param state -> state of the parsing
*/
void	put_struct(t_map *map, char *str, char state)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || is_in_set(str[i], "NOSWEAFC") == 1))
		i++;
	if (state == 'N')
		map->no = ft_strdup_stop_wspace(str + i);
	if (state == 'S')
		map->so = ft_strdup_stop_wspace(str + i);
	if (state == 'W')
		map->we = ft_strdup_stop_wspace(str + i);
	if (state == 'E')
		map->ea = ft_strdup_stop_wspace(str + i);
	if (state == 'F')
		map->f = ft_strdup(str + i);
	if (state == 'C')
		map->c = ft_strdup(str + i);
}

/* Parse the informations in the file
@param map -> t_map struct pointer
@param str -> line to parse
@return :
	1 = is information line
	0 = not information line
*/
int	parse_info(t_map *map, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (ft_strcmpv2(str + i, "NO", 2) == 0)
		return (put_struct(map, str + i, 'N'), 1);
	if (ft_strcmpv2(str + i, "SO", 2) == 0)
		return (put_struct(map, str + i, 'S'), 1);
	if (ft_strcmpv2(str + i, "WE", 2) == 0)
		return (put_struct(map, str + i, 'W'), 1);
	if (ft_strcmpv2(str + i, "EA", 2) == 0)
		return (put_struct(map, str + i, 'E'), 1);
	if (ft_strcmpv2(str + i, "F", 1) == 0)
		return (put_struct(map, str + i, 'F'), 1);
	if (ft_strcmpv2(str + i, "C", 1) == 0)
		return (put_struct(map, str + i, 'C'), 1);
	return (0);
}

/* Parse the file and check if there is the 6 required informations
@param map -> t_map struct pointer
@param file -> file to parse
@return :
	1 = informations are ok
	0 = informations are not ok
*/
int	parse_file(t_map *map, char *file)
{
	char	*line;
	int		fd;
	int		count;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (parse_info(map, line) == 1)
			count++;
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	if (count != 6)
		return (free(line), close(fd), 0);
	return (free(line), close(fd), 1);
}

/* Initialize the map structure and parse the file
@param map -> t_map struct pointer
@param file -> file to parse
@return :
	1 = map is initialized
	0 = map is not initialized
*/
int	init_map(t_map *map, char *file, t_window *data)
{
	map->map = NULL;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->f = NULL;
	map->c = NULL;
	if (!parse_file(map, file))
		return (error_msg("Bad informations amount"), 0);
	if (!alloc_map(map, file))
		return (0);
	if (!check_all(map, data))
		return (0);
	if (!parse_color_f(map))
		return (error_msg("Bad floor color"), 0);
	if (!parse_color_c(map))
		return (error_msg("Bad ceil color"), 0);
	return (1);
}
