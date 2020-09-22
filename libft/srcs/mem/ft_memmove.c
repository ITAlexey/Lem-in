/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:14:46 by dshala            #+#    #+#             */
/*   Updated: 2019/09/16 20:18:26 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*str;
	unsigned char		*dst;

	if (n == 0 || dest == src)
		return (dest);
	dst = (unsigned char*)dest;
	str = (unsigned char*)src;
	if (dst > str)
	{
		while (n--)
			dst[n] = str[n];
	}
	else
		return (ft_memcpy(dst, str, n));
	return (dst);
}
