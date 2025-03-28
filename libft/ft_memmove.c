/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:50:23 by hetya             #+#    #+#             */
/*   Updated: 2021/11/17 14:56:17 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * copy the memory pointed by dst in the src area for a lenght of n 
 * and it run when the 2 area overlapsing ieach other
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*ptr_src;
	char	*ptr_dst;

	i = len + 1;
	if (!dst && !src)
		return (NULL);
	ptr_src = (char *) src;
	ptr_dst = (char *) dst;
	if (dst > src)
	{
		while (--i > 0)
		{
			ptr_dst[i - 1] = ptr_src[i - 1];
		}
	}
	else
	{
		i = -1;
		while (++i < len)
		{
			ptr_dst[i] = ptr_src[i];
		}
	}
	return (dst);
}
