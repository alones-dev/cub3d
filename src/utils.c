/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:26:39 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/23 16:40:08 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Print an error message in the standard error output
@param str -> message to print in the error output
*/
void	error_msg(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
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
