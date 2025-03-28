/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:31:57 by hetya             #+#    #+#             */
/*   Updated: 2021/11/09 12:59:44 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * setup the memorie to 0 take a pointeur for the start of the area and a length
 * for the define the length of the area to setup to 0
*/
void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *) s;
	while (i < n)
	{
		ptr[i] = 0;
		s++;
		i++;
	}
}
