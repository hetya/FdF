/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:57:52 by hetya             #+#    #+#             */
/*   Updated: 2022/03/22 18:03:42 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * check if the char c is in the base and return its index
 * return -1 if the char is not in the base
*/
static int	in_base(char *base, char c)
{
	int	i;

	i = -1;
	while (base[++i])
	{
		if (base[i] == c)
			return (i);
	}
	return (-1);
}

/**
 * convert a hexadecimal string in int
 * if str is in lowercase it will convert it in uppercase
*/
int	ft_atoi_hexa(char *str)
{
	char	*base;
	int		nbr;
	int		signe;
	int		i;

	base = "0123456789ABCDEF";
	str = ft_strupcase(str);
	i = 0;
	nbr = 0;
	signe = 1;
	while (str[i] == ' ')
		i++;
	i--;
	while (str[++i] == '+' || str[i] == '-')
		if (str[i] == '-')
			signe *= -1;
	while (str[i] != '\0')
	{
		if (in_base(base, str[i]) == -1)
			return (nbr);
		nbr = nbr * ft_strlen(base) + in_base(base, str[i]);
		i++;
	}
	return (nbr * signe);
}
