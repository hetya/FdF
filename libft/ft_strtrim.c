/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:15:45 by hetya             #+#    #+#             */
/*   Updated: 2021/12/01 18:12:10 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * verif if the chararceter c is in the str string
*/
static int	verif(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

/**
 * return new string of the string s1 , without all the character contained in
 * the set string at the start or the end of the string s1
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (s1)
	{
		i = 0;
		j = ft_strlen(s1) - 1;
		while (!(verif(set, s1[i])) && s1[i])
			i++;
		while (!(verif(set, s1[j])) && j > i)
			j--;
		return (ft_substr(s1, i, j - i + 1));
	}
	return (NULL);
}
