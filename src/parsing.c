/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:37:16 by kdaumont          #+#    #+#             */
/*   Updated: 2024/04/16 17:05:11 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
