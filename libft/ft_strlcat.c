/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:22:06 by hetya             #+#    #+#             */
/*   Updated: 2021/11/11 13:13:33 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * strlcat appends the src string to the end of dst for a most
 * length of dstsize - ft_strlen(dst) - 1 characters and then it will NUL
 * terminate unless dstsize is 0 or the original dst string was longer than
 * dstsize
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_dest;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dst);
	while (dst[i] != '\0' && i < dstsize)
		i++;
	j = i;
	if (dstsize < len_dest || dstsize == 0)
		return (len_src + dstsize);
	if (len_dest < dstsize)
	{
		i = 0;
		while ((i < dstsize - len_dest - 1) && src[i])
		{
			dst[len_dest + i] = src[i];
			i++;
		}
	}
	if (i > 0)
		dst[len_dest + i] = '\0';
	return (len_src + j);
}
