/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:44:27 by hetya             #+#    #+#             */
/*   Updated: 2021/11/09 13:00:10 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * write a number (n) in the file directory fd
*/
void	ft_putnbr_fd(int n, int fd)
{
	char	caractere;
	int		v;
	int		neg;

	caractere = n % 10 + '0';
	v = n / 10;
	if (n < 0)
	{
		v = -v;
		neg = n % 10;
		neg = -neg;
		caractere = neg + '0';
		write(fd, "-", 1);
	}
	if (v >= 1)
	{
		ft_putnbr_fd(v, fd);
	}
	write(fd, &caractere, 1);
}
