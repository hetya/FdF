/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:42:56 by hetya             #+#    #+#             */
/*   Updated: 2021/11/09 12:59:41 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * this fonction return the sign of the number
 */
static int	operator(const char *str, size_t i)
{
	size_t		sign;

	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	return (sign);
}

/**
 * convert the number from int to char *
 */
int	ft_atoi(const char *str)
{
	size_t		i;
	int			total;
	int			sign;

	i = 0;
	total = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = operator(str, i);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
		{
			break ;
		}
		total = total * 10 + (str[i] - '0');
		i++;
	}
	return (total * sign);
}
