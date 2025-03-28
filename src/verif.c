/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 01:30:09 by hetya             #+#    #+#             */
/*   Updated: 2022/02/03 00:57:36 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_error(int nb)
{
	if (nb == 0)
		return (0);
	else if (nb == 1)
		write(2, "Error : parameter\n", 18);
	else if (nb == 2)
		write(2, "Error : opening the file\n", 25);
	else if (nb == 3)
		write(2, "Error : initializing mlx\n", 25);
	else if (nb == 4)
		write(2, "Error : creating the window\n", 28);
	else if (nb == 5)
		write(2, "Error : creating the image\n", 27);
	else if (nb == 6)
		write(2, "Error : parameter\n", 18);
	else if (nb == 7)
		write(2, "Error : map\n", 12);
	else if (nb == 8)
		write(2, "Error : map file empty\n", 23);
	else if (nb == 9)
		write(2, "Error : split\n", 14);
	else if (nb == 10)
		write(2, "Error : malloc\n", 15);
	else if (nb == 11)
		write(2, "Error : buffer\n", 15);
	exit(EXIT_FAILURE);
}
