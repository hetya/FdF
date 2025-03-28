/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:31:53 by hetya             #+#    #+#             */
/*   Updated: 2021/11/09 13:00:06 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * uint8_t : unsigned 8-bit integer type
 * 
 * setup the area pointed by b with c for a length of len
 * 
 */

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	uint8_t			*ptr;
	unsigned char	c1;

	i = 0;
	ptr = (uint8_t *) b;
	c1 = (unsigned char) c;
	while (i < len)
	{
		ptr[i] = c1;
		i++;
	}
	return (b);
}
