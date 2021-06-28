/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araramya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:22:06 by araramya          #+#    #+#             */
/*   Updated: 2021/02/04 12:45:19 by araramya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_cpy;
	unsigned char	*src_cpy;
	unsigned char	c_cpy;
	size_t			i;

	dst_cpy = (unsigned char*)dst;
	src_cpy = (unsigned char*)src;
	c_cpy = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		*(dst_cpy + i) = *(src_cpy + i);
		if (*(src_cpy + i) == c_cpy)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
