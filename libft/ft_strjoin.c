/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:34:23 by hetya             #+#    #+#             */
/*   Updated: 2022/03/22 18:04:33 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * this function return the two string s1 s2 in a new string join
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	if (!s1)
		return (ft_strdup(s2));
	join = (char *)ft_calloc(sizeof(char),
			(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	while (s1[++j])
	{
		join[i] = s1[j];
		i++;
	}
	j = -1;
	while (s2[++j])
	{
		join[i] = s2[j];
		i++;
	}
	join[i] = '\0';
	return (join);
}
