/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:24:11 by hetya             #+#    #+#             */
/*   Updated: 2022/03/22 18:05:01 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = ft_strlen(str);
	j = 0;
	if (to_find[0] == '\0')
		return (str);
	while (i != 0)
	{
		j = 0;
		while (to_find[j] != '\0' && str[i + j] == to_find[j])
			j++;
		if (to_find[j] == '\0')
			return (str + i);
		i--;
	}
	return (0);
}
