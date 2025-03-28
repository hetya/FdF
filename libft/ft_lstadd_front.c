/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:43:10 by hetya             #+#    #+#             */
/*   Updated: 2021/11/10 11:21:02 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * this fonction make next element of the new lst pointed on the first element
 * of lst and change the adress that pointed of the first element
*/
void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst)
	{
		new->next = *(alst);
	}
	*alst = new;
}
