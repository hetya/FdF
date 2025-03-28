/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:27:01 by hetya             #+#    #+#             */
/*   Updated: 2021/11/09 12:59:59 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * search c in the memory pointed by the pointer s, with the length n
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	*ptr_src;

	ptr_src = (unsigned char *)s;
	i = 0;
	c1 = (unsigned char) c;
	while (i < n)
	{
		if (ptr_src[i] == c1)
			return ((void *) &ptr_src[i]);
		i++;
	}
	return (NULL);
}
