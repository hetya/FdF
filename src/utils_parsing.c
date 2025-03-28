/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:34:09 by hetya             #+#    #+#             */
/*   Updated: 2022/02/03 02:48:23 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color(t_ptr_mlx *ptr_mlx, char *color)
{
	int	trgb;

	if (color != NULL)
	{
		color = color + 2;
		trgb = ft_atoi_base(ft_strlowcase(color), "0123456789abcdef");
	}
	else
		trgb = 0xffffff;
	ptr_mlx->fdf->tab[ptr_mlx->fdf->len_tab].color.r = ((trgb >> 16) & 0xFF);
	ptr_mlx->fdf->tab[ptr_mlx->fdf->len_tab].color.g = ((trgb >> 8) & 0xFF);
	ptr_mlx->fdf->tab[ptr_mlx->fdf->len_tab].color.b = ((trgb) & 0xFF);
}

void	center_value(t_ptr_mlx *ptr_mlx)
{
	int	i;

	i = 0;
	while (i < ptr_mlx->fdf->len_tab)
	{
		ptr_mlx->fdf->tab[i].x = (ptr_mlx->fdf->tab[i].x - ptr_mlx->fdf->x_max
				/ 2);
		ptr_mlx->fdf->tab[i].y = (ptr_mlx->fdf->tab[i].y - ptr_mlx->fdf->y_max
				/ 2);
		ptr_mlx->fdf->tab[i].z = (ptr_mlx->fdf->tab[i].z
				- (ptr_mlx->fdf->greater_value
					- ptr_mlx->fdf->smaller_value) / 2);
		i++;
	}
}

void	destroy_mlx(t_ptr_mlx *ptr_mlx, void *ptr, int error)
{
	free(ptr);
	mlx_destroy_image(ptr_mlx->mlx, ptr_mlx->data->img);
	mlx_destroy_window(ptr_mlx->mlx, ptr_mlx->win);
	fdf_error(error);
}
