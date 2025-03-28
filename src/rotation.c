/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:32:05 by hetya             #+#    #+#             */
/*   Updated: 2022/02/12 18:18:38 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * z rotation :
 * point->z = ((tmp.x * matrix[2]) + (tmp.y * matrix[5]) + (tmp.z * matrix[8]));
*/
void	mult_matrix(t_ptr_mlx *ptr_mlx, t_point *point, t_point *angle)
{
	t_point	tmp;
	float	ax;
	float	ay;
	float	az;
	float	matrix[9];

	ax = 0 + ft_degtorad(angle->x);
	ay = 0 + ft_degtorad(angle->y);
	az = ptr_mlx->fdf->angle + ft_degtorad(angle->z);
	tmp.x = point->x;
	tmp.y = point->y;
	tmp.z = point->z;
	matrix[0] = cos(ay) * cos(az);
	matrix[1] = cos(ay) * sin(az);
	matrix[2] = -sin(ay);
	matrix[3] = sin(ax) * sin(ay) * cos(az) - cos(ax) * sin(az);
	matrix[4] = sin(ax) * sin(ay) * sin(az) + cos(ax) * cos(az);
	matrix[5] = sin(ax) * cos(ay);
	point->x = ((tmp.x * matrix[0]) + (tmp.y * matrix[1]) + (tmp.z * matrix[2]))
		* ptr_mlx->fdf->zoom / 2 + ptr_mlx->fdf->x_translation;
	point->y = ((tmp.x * matrix[3]) + (tmp.y * matrix[4]) + (tmp.z * matrix[5]))
		* ptr_mlx->fdf->zoom / 2 + ptr_mlx->fdf->y_translation;
}

int	rotation(t_ptr_mlx *ptr_mlx, int ax, int ay, int az)
{
	int		i;
	t_point	angle;

	angle.x = ax;
	angle.y = ay;
	angle.z = az;
	i = 0;
	while (i < ptr_mlx->fdf->len_tab)
	{
		mult_matrix(ptr_mlx, &ptr_mlx->fdf->tab[i], &angle);
		i++;
	}
	return (0);
}
