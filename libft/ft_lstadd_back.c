/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araramya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:21:22 by araramya          #+#    #+#             */
/*   Updated: 2021/02/02 17:07:31 by araramya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last_elem;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last_elem = ft_lstlast(*lst);
			last_elem->next = new;
		}
	}
}
