/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araramya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:06:19 by araramya          #+#    #+#             */
/*   Updated: 2021/02/04 13:18:03 by araramya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*src_cpy;
	char	*dst_cpy;
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_cpy = dst;
	src_cpy = (char*)src;
	i = 0;
	while (i < n)
	{
		*(dst_cpy + i) = *(src_cpy + i);
		i++;
	}
	return (dst);
}
