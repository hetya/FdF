/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 02:48:09 by hetya             #+#    #+#             */
/*   Updated: 2022/02/08 03:50:34 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * swap two element at the given parameters i and j
*/
static void	swap(int *arr, int i, int j)
{
	int	tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

/**
 * take the last parameter that is the most left position of the array that we
 * want's to sort and initialized the pivot point at this value
*/
static int	partition(int *arr, int left, int right)
{
	int	pivot;
	int	i;
	int	j;

	i = left;
	j = left - 1;
	pivot = arr[right];
	while (i < right)
	{
		if (arr[i] < pivot)
		{
			j++;
			swap(arr, j, i);
		}
		i++;
	}
	swap(arr, j + 1, right);
	return (j + 1);
}

/**
 * the the part before the pivot abd then recal the function to sort the part
 * after the pivot
*/
static void	quick_sort(int *arr, int left, int right)
{
	int	pi;

	if (left < right)
	{
		pi = partition(arr, left, right);
		quick_sort(arr, pi + 1, right);
		quick_sort(arr, left, pi - 1);
	}
}

/**
 * check if the tab is sort and sort it if not
 * return tab
*/
int	*ft_sort_tab(int *tab, size_t len)
{
	if (ft_tab_is_sort(tab, len) != 0)
		quick_sort(tab, 0, len);
	return (tab);
}
