/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 03:35:51 by hetya             #+#    #+#             */
/*   Updated: 2022/03/04 16:29:40 by hetya            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * search the median of arr given in parameter
*/
int	ft_median(int *arr, int len)
{
	int	*ptr;
	int	median;

	ptr = (int *)ft_calloc(sizeof(int), len);
	if (!ptr)
		exit (EXIT_FAILURE);
	ft_memcpy(ptr, arr, len * sizeof(int));
	ptr = ft_sort_tab(ptr, len);
	if (len % 2 == 0)
		median = ptr[((len) / 2) - 1];
	else
		median = ptr[((len) / 2)];
	free(ptr);
	return (median);
}
