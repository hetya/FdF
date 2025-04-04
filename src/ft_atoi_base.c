/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:01:52 by hetya             #+#    #+#             */
/*   Updated: 2022/02/02 21:23:43 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	atoi_base_error(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (-1);
	while (base[i] != '\0' || base[0] == '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (i != j && base[i] == base[j])
				return (-1);
			j++;
		}
		if (base[i] == '+' || base[i] == '-' || (base[i] >= 9 && base[i] <= 13))
			return (-1);
		i++;
	}
	return (1);
}

static int	value(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (0);
}

static int	in_base(char *base, char c)
{
	int	i;

	i = -1;
	while (base[++i])
	{
		if (base[i] == c)
			return (1);
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		nbr;
	int		signe;
	int		i;

	i = 0;
	nbr = 0;
	signe = 1;
	if (atoi_base_error(base) == -1)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (in_base(base, str[i]) == -1)
			return (nbr);
		nbr = nbr * ft_strlen(base) + value(base, str[i]);
		i++;
	}
	return (nbr * signe);
}
