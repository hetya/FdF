/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 03:59:32 by hetya             #+#    #+#             */
/*   Updated: 2022/02/03 19:25:06 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*title(char *str)
{
	int	i;

	i = 0;
	if (ft_strncmp(&str[ft_strlen(str) - 4], ".fdf", 4) == 0)
		str[ft_strlen(str) - 4] = 0;
	while (str[i] != '\0' && ft_strchr(&str[i], '/') != NULL)
		i++;
	return (&str[i]);
}

int	loop_hook(t_ptr_mlx *ptr_mlx)
{
	if (ptr_mlx->fdf->switch_color == 1)
		color(ptr_mlx);
	if (ptr_mlx->fdf->is_rotation == 1)
		ptr_mlx->fdf->angle += 0.006;
	draw_map(ptr_mlx, ptr_mlx->fdf->tab, ptr_mlx->fdf->len_tab);
	return (0);
}

void	white_map(t_ptr_mlx *ptr_mlx)
{
	int		i;

	i = 0;
	while (i < ptr_mlx->fdf->len_tab)
	{
		ptr_mlx->fdf->tab[i].color = ptr_mlx->fdf->t_color;
		i++;
	}
}

float	float_percent(int min, int max, int current)
{
	float	position;

	if (min == max)
		return (1);
	if (current == min)
		return (0);
	position = current - min;
	return (ft_abs(position / (max - min)));
}
