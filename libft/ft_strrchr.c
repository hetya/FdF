/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:07:41 by hetya             #+#    #+#             */
/*   Updated: 2021/11/11 12:47:07 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * search the last occurence of c in the string s
*/
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	c1;

	i = ft_strlen(s);
	c1 = (char) c;
	while (i >= 0)
	{
		if (s[i] == c1)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}
