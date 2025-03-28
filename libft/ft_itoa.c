/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:50:51 by hetya             #+#    #+#             */
/*   Updated: 2022/03/04 16:27:23 by hetya            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * return the number of digit that compose the number
*/
static size_t	len_int(long int nbr)
{
	size_t	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

/**
 * reverse the pointer
*/
static void	rev(char *ptr)
{
	size_t	i;
	size_t	j;
	int		swap;

	i = 0;
	j = ft_strlen(ptr) - 1;
	while (i < j)
	{
		swap = ptr[i];
		ptr[i] = ptr[j];
		ptr[j] = swap;
		j--;
		i++;
	}
}

/**
 * fill the pointer given in parameter with char corresponding to the number
 * but reverse then the function call rev to reverse the string to make it 
 * corresponding to the number 
*/
static void	fill(char *ptr, int n, long int nbr, int is_neg)
{
	char		caractere;
	size_t		i;

	i = 0;
	while (nbr != 0)
	{
		caractere = nbr % 10 + '0';
		nbr = nbr / 10;
		ptr[i] = caractere;
		i++;
	}
	if (n == 0)
	{
		ptr[i] = '0';
		i++;
	}
	if (is_neg)
	{
		ptr[i] = '-';
		i++;
	}
	ptr[i] = '\0';
}

/**
 * global : convert a number in a string
*/
char	*ft_itoa(int n)
{
	char		*ptr;
	int			is_neg;
	long int	nbr;

	nbr = (long int) n;
	is_neg = 0;
	if (n < 0)
		is_neg = 1;
	if (is_neg)
	{
		nbr = -nbr;
	}
	ptr = (char *)ft_calloc(sizeof(char), (len_int(nbr) + is_neg + 1));
	if (!ptr)
		return (NULL);
	fill(ptr, n, nbr, is_neg);
	if (len_int(nbr) > 1 || is_neg)
		rev(ptr);
	return (ptr);
}
