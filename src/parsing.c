/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:43:37 by hetya             #+#    #+#             */
/*   Updated: 2025/02/25 00:02:43 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**create_split(t_ptr_mlx *ptr_mlx, t_list *list, t_list *listb)
{
	char	**split;
	int		len_split;

	split = ft_split(list->content, ' ');
	if (split == NULL)
	{
		ft_lstclear(&listb, free);
		destroy_mlx(ptr_mlx, NULL, 9);
	}
	len_split = split_len(split);
	if (ptr_mlx->fdf->x_max == 0)
		ptr_mlx->fdf->x_max = len_split;
	if (ptr_mlx->fdf->x_max != len_split)
	{
		free_split(split);
		ft_lstclear(&listb, free);
		destroy_mlx(ptr_mlx, NULL, 7);
	}
	return (split);
}

void	create_tab(t_ptr_mlx *ptr_mlx, char **split, t_list *list)
{
	if (ptr_mlx->fdf->tab == NULL)
	{
		ptr_mlx->fdf->tab = calloc(ptr_mlx->fdf->x_max * ptr_mlx->fdf->y_max,
				sizeof(t_point));
		ptr_mlx->fdf->reset = calloc(ptr_mlx->fdf->x_max * ptr_mlx->fdf->y_max,
				sizeof(t_point));
		if (!ptr_mlx->fdf->tab || !ptr_mlx->fdf->reset)
		{
			free(ptr_mlx->fdf->reset);
			free_split(split);
			ft_lstclear(&list, free);
			destroy_mlx(ptr_mlx, ptr_mlx->fdf->tab, 10);
		}
	}
}

int	fill_tab(t_ptr_mlx *ptr_mlx, int len_split, char **split, int j)
{
	char	**split_value;
	int		i;
	int		z;

	z = 0;
	i = 0;
	while (i < len_split && (split[i][0] != '\0'))
	{
		split_value = ft_split(split[i], ',');
		if (!split_value)
			return (-1);
		z = ft_atoi(split_value[0]);
		if ((i == 0 && j == 0) || z > ptr_mlx->fdf->greater_value)
			ptr_mlx->fdf->greater_value = z;
		if ((i == 0 && j == 0) || z < ptr_mlx->fdf->smaller_value)
			ptr_mlx->fdf->smaller_value = z;
		ptr_mlx->fdf->tab[ptr_mlx->fdf->len_tab].x = i;
		ptr_mlx->fdf->tab[ptr_mlx->fdf->len_tab].y = j;
		ptr_mlx->fdf->tab[ptr_mlx->fdf->len_tab].z = z;
		set_color(ptr_mlx, split_value[1]);
		ptr_mlx->fdf->len_tab++;
		free_split(split_value);
		i++;
	}
	return (0);
}

void	create_matrix(t_ptr_mlx *ptr_mlx, t_list *list)
{
	int		j;
	int		len_split;
	char	**split;
	t_list	*listb;

	j = -1;
	listb = list;
	while (list != NULL)
	{
		split = create_split(ptr_mlx, list, listb);
		if (split == NULL)
			destroy_mlx(ptr_mlx, ptr_mlx->fdf->tab, 9);
		len_split = split_len(split);
		create_tab(ptr_mlx, split, listb);
		if (fill_tab(ptr_mlx, len_split, split, ++j) == -1)
		{
			free(ptr_mlx->fdf->reset);
			free_split(split);
			ft_lstclear(&listb, free);
			destroy_mlx(ptr_mlx, ptr_mlx->fdf->tab, 11);
		}
		free_split(split);
		list = list->next;
	}
}

void	parse(t_ptr_mlx *ptr_mlx, int fd)
{
	char		*buf;
	int			y;
	t_list		*list;

	y = 0;
	buf = get_next_line(fd);
	if (buf == NULL)
		fdf_error(8);
	while (buf != NULL)
	{
		if (y == 0)
			list = ft_lstnew(buf);
		else
			ft_lstadd_back(&list, ft_lstnew(buf));
		y++;
		buf = get_next_line(fd);
	}
	ptr_mlx->fdf->y_max = y;
	create_matrix(ptr_mlx, list);
	ft_lstclear(&list, free);
	center_value(ptr_mlx);
	ptr_mlx->fdf->reset = ft_memcpy(ptr_mlx->fdf->reset, ptr_mlx->fdf->tab,
			ptr_mlx->fdf->len_tab * sizeof(t_point));
	draw_map(ptr_mlx, ptr_mlx->fdf->tab, ptr_mlx->fdf->len_tab);
}
