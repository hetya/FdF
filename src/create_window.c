/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 01:46:27 by hetya             #+#    #+#             */
/*   Updated: 2022/01/06 04:04:42 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*create_window(void *mlx, char *name, int weidth, int high)
{
	void	*win;

	win = mlx_new_window(mlx, weidth, high, name);
	if (win == NULL)
		return (NULL);
	return (win);
}
