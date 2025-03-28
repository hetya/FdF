/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:37:29 by hetya             #+#    #+#             */
/*   Updated: 2021/11/09 17:57:42 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * copy the memory pointed by dst in the src area for a lenght of n
*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*ptr;
	char	*ptr_src;

	if (!dst && !src)
		return (NULL);
	i = 0;
	ptr = (char *)dst;
	ptr_src = (char *) src;
	while (i < n)
	{
		ptr[i] = ptr_src[i];
		i++;
	}
	return (dst);
}
