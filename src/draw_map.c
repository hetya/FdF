/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:53:21 by hetya             #+#    #+#             */
/*   Updated: 2025/02/25 02:04:34 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	in_window(t_ptr_mlx *ptr_mlx, t_point point)
{
	if ((point.x > 0 && point.x < ptr_mlx->fdf->width)
		&& (point.y > 0 && point.y < ptr_mlx->fdf->high))
		return (1);
	return (-1);
}

void	draw(t_ptr_mlx *ptr_mlx, t_point *tab, int i)
{
	t_point	iso[3];

	iso[0] = tab[i];
	if (i > ptr_mlx->fdf->x_max - 1)
		iso[1] = tab[i - ptr_mlx->fdf->x_max];
	if (i % ptr_mlx->fdf->x_max)
		iso[2] = tab[i - 1];
	if (i > ptr_mlx->fdf->x_max - 1 && (in_window(ptr_mlx, iso[0]) != -1
			|| in_window(ptr_mlx, iso[1]) != -1))
		bresenham_segement(ptr_mlx, iso[0], iso[1]);
	if (i % ptr_mlx->fdf->x_max + 1 > 1 && (in_window(ptr_mlx, iso[0]) != -1
			|| in_window(ptr_mlx, iso[2]) != -1))
		bresenham_segement(ptr_mlx, iso[0], iso[2]);
}

void	draw_para(t_ptr_mlx *ptr_mlx, t_point *tab, int len_tab)
{
	int		i;

	i = -1;
	ptr_mlx->fdf->angle = 0;
	rotation(ptr_mlx, 90, -180, 0);
	while (++i < len_tab)
		draw(ptr_mlx, tab, i);
}

void	draw_map(t_ptr_mlx *ptr_mlx, t_point *tab, int len_tab)
{
	int		i;

	i = -1;
	ft_memset(ptr_mlx->data->addr, 0, ptr_mlx->data->img_size);
	if (ptr_mlx->fdf->is_para == 0)
	{
		rotation(ptr_mlx, -55, 0, -45);
		if (ft_abs(ft_radtodeg(ptr_mlx->fdf->angle - 45)) % 360 > 90
			&& ft_abs(ft_radtodeg(ptr_mlx->fdf->angle - 45)) % 360 <= 284)
		{
			i = len_tab;
			while (0 <= --i)
				draw(ptr_mlx, tab, i);
		}
		else
			while (++i < len_tab)
				draw(ptr_mlx, tab, i);
	}
	else
		draw_para(ptr_mlx, tab, len_tab);
	mlx_put_image_to_window(ptr_mlx->mlx, ptr_mlx->win,
		ptr_mlx->data->img, 0, 0);
	ft_memcpy(ptr_mlx->fdf->tab, ptr_mlx->fdf->reset,
		ptr_mlx->fdf->len_tab * sizeof(t_point));
}
