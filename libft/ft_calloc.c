/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araramya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:04:52 by araramya          #+#    #+#             */
/*   Updated: 2021/07/05 20:48:44 by araramya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*z_arr;

	z_arr = (void *)malloc(count * size);
	if (!z_arr)
		return (NULL);
	ft_memset(z_arr, 0, count * size);
	return (z_arr);
}
