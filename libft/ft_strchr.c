/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:27:32 by hetya             #+#    #+#             */
/*   Updated: 2021/11/11 12:46:50 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * search the first occurence of c in the string s
*/
char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			c1;

	i = 0;
	c1 = (char) c;
	while (s[i] != '\0')
	{
		if (s[i] == c1)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == c1)
		return ((char *) s + i);
	return (NULL);
}
