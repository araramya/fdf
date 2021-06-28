/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araramya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:04:52 by araramya          #+#    #+#             */
/*   Updated: 2021/02/01 19:07:20 by araramya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*z_arr;

	if (!(z_arr = (void*)malloc(count * size)))
		return (NULL);
	ft_memset(z_arr, 0, count * size);
	return (z_arr);
}
