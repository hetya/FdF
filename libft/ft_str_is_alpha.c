/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:11:30 by hetya             #+#    #+#             */
/*   Updated: 2022/02/08 02:31:00 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * this function check if str just letter
 * return -1 if not
*/
int	ft_str_is_alpha(char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 'A' || str[i] > 'Z')
			&& (str[i] < 'a' || str[i] > 'z'))
			return (-1);
		++i;
	}
	return (1);
}
