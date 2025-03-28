/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:34:08 by hetya             #+#    #+#             */
/*   Updated: 2025/02/25 00:57:35 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	intialize_mlx(char *name, t_ptr_mlx *ptr_mlx)
{
	ptr_mlx->mlx = mlx_init();
	if (ptr_mlx->mlx == NULL)
		fdf_error(3);
	ptr_mlx->fdf->high = 720;
	ptr_mlx->fdf->width = 1280;
	ptr_mlx->win = create_window(ptr_mlx->mlx, title(name), ptr_mlx->fdf->width,
			ptr_mlx->fdf->high);
	if (ptr_mlx->win == NULL)
		fdf_error(4);
}

void	fill_color(t_color *color, int r, int g, int b)
{
	color->r = r;
	color->g = g;
	color->b = b;
}

void	intialize_stucture(t_ptr_mlx *ptr_mlx)
{
	ptr_mlx->data->img = mlx_new_image(ptr_mlx->mlx, ptr_mlx->fdf->width,
			ptr_mlx->fdf->high);
	if (ptr_mlx->data->img == NULL)
		fdf_error(5);
	ptr_mlx->data->addr = mlx_get_data_addr(ptr_mlx->data->img,
			&ptr_mlx->data->bits_per_pixel, &ptr_mlx->data->line_length,
			&ptr_mlx->data->endian);
	ptr_mlx->data->bits_per_pixel /= 8;
	ptr_mlx->data->img_size = (ptr_mlx->fdf->high * ptr_mlx->data->line_length);
	ptr_mlx->fdf->zoom = 40;
	ptr_mlx->fdf->x_translation = ptr_mlx->fdf->width / 2;
	ptr_mlx->fdf->y_translation = ptr_mlx->fdf->high / 2;
	ptr_mlx->fdf->angle = 0;
	ptr_mlx->fdf->is_rotation = 0;
	ptr_mlx->fdf->switch_color = 0;
	ptr_mlx->fdf->is_para = 0;
	fill_color(&ptr_mlx->fdf->t_color, 255, 0, 0);
	ptr_mlx->fdf->x_max = 0;
	ptr_mlx->fdf->tab = NULL;
	ptr_mlx->fdf->len_tab = 0;
}

int	main(int argc, char **argv)
{
	t_ptr_mlx	ptr_mlx;
	t_fdf		fdf;
	t_data		data;
	int			fd;

	if (argc != 2)
		return (fdf_error(1));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (fdf_error(2));
	ptr_mlx.fdf = &fdf;
	ptr_mlx.data = &data;
	intialize_mlx(argv[1], &ptr_mlx);
	intialize_stucture(&ptr_mlx);
	mlx_mouse_hook(ptr_mlx.win, mouse_hook, &ptr_mlx);
	mlx_key_hook(ptr_mlx.win, key_hook, &ptr_mlx);
	mlx_hook(ptr_mlx.win, 17, 1L << 17, cleaning_fdf, &ptr_mlx);
	parse(&ptr_mlx, fd);
	mlx_loop_hook(ptr_mlx.mlx, loop_hook, &ptr_mlx);
	mlx_loop(ptr_mlx.mlx);
	exit(EXIT_SUCCESS);
}
