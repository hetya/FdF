/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:45:22 by hetya             #+#    #+#             */
/*   Updated: 2025/02/25 00:58:08 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	cleaning_fdf(t_ptr_mlx *ptr_mlx)
{
	mlx_destroy_image(ptr_mlx->mlx, ptr_mlx->data->img);
	mlx_destroy_window(ptr_mlx->mlx, ptr_mlx->win);
	free(ptr_mlx->fdf->tab);
	free(ptr_mlx->fdf->reset);
	exit(EXIT_SUCCESS);
}

void	check_translation(t_ptr_mlx *ptr_mlx, int key)
{
	if (key == KEY_Z || key == KEY_ARROW_UP)
		ptr_mlx->fdf->y_translation -= 5;
	else if (key == KEY_Q || key == KEY_ARROW_LEFT)
		ptr_mlx->fdf->x_translation -= 5;
	else if (key == KEY_S || key == KEY_ARROW_DOWN)
		ptr_mlx->fdf->y_translation += 5;
	else if (key == KEY_D || key == KEY_ARROW_RIGHT)
		ptr_mlx->fdf->x_translation += 5;
}

int	key_hook(int key, t_ptr_mlx *ptr_mlx)
{
	if (key == KEY_ESCAPE)
		cleaning_fdf(ptr_mlx);
	if (key == KEY_PAD_PLUS)
		ptr_mlx->fdf->zoom++;
	if (key == KEY_PAD_MINUS && ptr_mlx->fdf->zoom > 0)
		ptr_mlx->fdf->zoom--;
	check_translation(ptr_mlx, key);
	if (key == KEY_ENTER)
		ptr_mlx->fdf->angle = 0;
	if (key == KEY_P)
		ptr_mlx->fdf->is_para = !ptr_mlx->fdf->is_para;
	if (key == KEY_R)
		ptr_mlx->fdf->is_rotation = !ptr_mlx->fdf->is_rotation;
	if (key == KEY_C)
		ptr_mlx->fdf->switch_color = !ptr_mlx->fdf->switch_color;
	return (0);
}

int	mouse_hook(int key, int x, int y, t_ptr_mlx *ptr_mlx)
{
	int	modify;

	modify = 0;
	(void) x;
	(void) y;
	if (key == MOUSE_SCROLL_UP)
	{
		ptr_mlx->fdf->zoom += 5;
		modify = 1;
	}
	if (key == MOUSE_SCROLL_DOWN && ptr_mlx->fdf->zoom > 5)
	{
		ptr_mlx->fdf->zoom -= 5;
		modify = 1;
	}
	if (modify != 0)
		draw_map(ptr_mlx, ptr_mlx->fdf->tab, ptr_mlx->fdf->len_tab);
	return (0);
}
