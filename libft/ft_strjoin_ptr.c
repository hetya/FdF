/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 04:05:58 by hetya             #+#    #+#             */
/*   Updated: 2022/03/22 18:04:45 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * return the length of s (without conting the '\0')
*/
static size_t	joinptrlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		++i;
	}
	return (i);
}

/**
 * this function return the two string s1 s2 in a new string join and free s1
*/
char	*ft_strjoin_ptr(char *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	if (s2 == NULL)
		return (s1);
	join = (char *)ft_calloc(sizeof(char),
			(joinptrlen(s1) + joinptrlen(s2) + 1));
	if (!join)
		return (NULL);
	if (s1 != NULL)
		while (s1[++j])
			join[i++] = s1[j];
	j = -1;
	while (s2[++j])
		join[i++] = s2[j];
	free(s1);
	join[i] = '\0';
	return (join);
}
