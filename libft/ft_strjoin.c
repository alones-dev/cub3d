/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:16:41 by cornguye          #+#    #+#             */
/*   Updated: 2024/04/23 13:08:46 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const s2)
{
	unsigned int	i;
	unsigned int	compteur;
	char			*new_chaine;

	if (!s1)
		return (0);
	write(1, "TEST", 4);
	i = 0;
	compteur = 0;
	new_chaine = malloc(sizeof(char) * (ft_strlen(s1) + 1 + 1));
	if (!new_chaine)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		new_chaine[compteur] = s1[i];
		i++;
		compteur++;
	}
	i = 0;
	new_chaine[compteur] = s2;
	i++;
	new_chaine[compteur++] = '\0';
	return (new_chaine);
}

char	*ft_strjoin3(const char *s1, const char *s2, const char *s3)
{
	char	*join;
	size_t	length;

	if (!s1 || !s2 || !s3)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1;
	join = ft_calloc(length, 1);
	if (!join)
		return (NULL);
	ft_strlcat(join, s1, length);
	ft_strlcat(join, s2, length);
	ft_strlcat(join, s3, length);
	return (join);
}
