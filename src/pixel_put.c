/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 01:35:18 by hetya             #+#    #+#             */
/*   Updated: 2022/01/19 00:33:15 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_pixel_put_on_img(t_ptr_mlx *ptr_mlx, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= ptr_mlx->fdf->width || y < 0 || y >= ptr_mlx->fdf->high)
		return ;
	dst = ptr_mlx->data->addr + (y * ptr_mlx->data->line_length + x
			* (ptr_mlx->data->bits_per_pixel));
	*(unsigned int *) dst = color;
}
