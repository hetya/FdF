/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_degtorad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 23:55:05 by hetya             #+#    #+#             */
/*   Updated: 2022/02/02 23:58:42 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * this function transform degre to radians
*/
float	ft_degtorad(int degre)
{
	float	radian;

	radian = (degre * PI) / 180;
	return (radian);
}
