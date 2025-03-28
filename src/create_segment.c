/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_segment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 04:39:41 by hetya             #+#    #+#             */
/*   Updated: 2022/02/03 02:48:26 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	lerp(t_point p1, t_point p2, float value)
{
	int	r;
	int	g;
	int	b;

	r = p1.color.r + (p2.color.r - p1.color.r) * value;
	g = p1.color.g + (p2.color.g - p1.color.g) * value;
	b = p1.color.b + (p2.color.b - p1.color.b) * value;
	return (create_trgb(0, r, g, b));
}

static void	initialisation_bresenham(t_line *line, t_point p1, t_point p2)
{
	line->x = p1.x;
	line->y = p1.y;
	line->dx = ft_abs(p2.x - p1.x);
	if (p1.x < p2.x)
		line->sx = 1;
	else
		line->sx = -1;
	line->dy = -ft_abs(p2.y - p1.y);
	if (p1.y < p2.y)
		line->sy = 1;
	else
		line->sy = -1;
	line->err = line->dx + line->dy;
}

void	bresenham_segement(t_ptr_mlx *ptr_mlx, t_point p1, t_point p2)
{
	t_line	line;

	initialisation_bresenham(&line, p1, p2);
	while (1)
	{
		if (line.dx > line.dy)
			line.percent = float_percent(line.x, p2.x, p1.x);
		else
			line.percent = float_percent(line.y, p2.y, p1.y);
		mlx_pixel_put_on_img(ptr_mlx, p1.x, p1.y, lerp(p1, p2, line.percent));
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		line.e2 = 2 * line.err;
		if (line.e2 >= line.dy)
		{
			line.err += line.dy;
			p1.x += line.sx;
		}
		if (line.e2 <= line.dx)
		{
			line.err += line.dx;
			p1.y += line.sy;
		}
	}
}
