/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:10:06 by hetya             #+#    #+#             */
/*   Updated: 2022/02/03 02:47:44 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	color(t_ptr_mlx *ptr_mlx)
{
	int	i;

	i = 0;
	if (ptr_mlx->fdf->t_color.g < 255 && ptr_mlx->fdf->t_color.b == 0)
		ptr_mlx->fdf->t_color.g += 5;
	else if (ptr_mlx->fdf->t_color.g == 255 && ptr_mlx->fdf->t_color.r > 0)
		ptr_mlx->fdf->t_color.r -= 5;
	else if (ptr_mlx->fdf->t_color.b < 255 && ptr_mlx->fdf->t_color.r == 0)
		ptr_mlx->fdf->t_color.b += 5;
	else if (ptr_mlx->fdf->t_color.b == 255 && ptr_mlx->fdf->t_color.g > 0)
		ptr_mlx->fdf->t_color.g -= 5;
	else if (ptr_mlx->fdf->t_color.r < 255)
		ptr_mlx->fdf->t_color.r += 5;
	else if (ptr_mlx->fdf->t_color.r == 255 && ptr_mlx->fdf->t_color.b > 0)
		ptr_mlx->fdf->t_color.b -= 5;
	while (i < ptr_mlx->fdf->len_tab)
	{
		ptr_mlx->fdf->tab[i].color = ptr_mlx->fdf->t_color;
		i++;
	}
	return (0);
}
