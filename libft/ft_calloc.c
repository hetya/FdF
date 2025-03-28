/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:32:02 by hetya             #+#    #+#             */
/*   Updated: 2022/03/04 15:59:24 by hetya            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * malloc an area of the size count * size and setup it to zero (with bzero)
*/
void	*ft_calloc(size_t count, size_t size)
{
	size_t	bytes;
	void	*ptr;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	bytes = count * size;
	ptr = (void *)malloc(bytes);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, bytes);
	return (ptr);
}
