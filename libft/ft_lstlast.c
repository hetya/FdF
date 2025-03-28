/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:45:59 by hetya             #+#    #+#             */
/*   Updated: 2021/11/11 12:38:39 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * browse all the list and return the last element of it
*/
t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst && lst->next != NULL)
		{
			lst = lst->next;
		}
	}
	return (lst);
}
