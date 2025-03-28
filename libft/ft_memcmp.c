/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:00:09 by hetya             #+#    #+#             */
/*   Updated: 2021/11/09 13:00:02 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * compared the 2 area of memory (s1, s2) in a length of n
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*ptr_s1;
	char	*ptr_s2;

	i = 0;
	ptr_s1 = (char *)s1;
	ptr_s2 = (char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (ptr_s1[i] != ptr_s2[i])
			return ((unsigned char) ptr_s1[i] - (unsigned char) ptr_s2[i]);
		i++;
	}
	return (0);
}
