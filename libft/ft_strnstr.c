/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:20:15 by hetya             #+#    #+#             */
/*   Updated: 2021/11/11 13:30:13 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * search a string needle in a other string haystack characters that appears
 * after a `\0' are not searched
 * Return a pointer to the first character of the first occurrence is
 * returned, unless if needle is an empty string, haystack will be returned,
 * if needle occurs nowhere in haystack, NULL is returned; 
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *) haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] != '\0' && haystack[i + j] == needle[j] && i + j < len)
		{
			j++;
		}
		if (needle[j] == '\0')
			return ((char *) haystack + i);
		i++;
	}
	return (0);
}
