/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:59:53 by dshala            #+#    #+#             */
/*   Updated: 2019/09/16 20:16:40 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*str;
	unsigned char		*dst;
	unsigned char		ch;

	ch = (unsigned char)c;
	dst = (unsigned char*)dest;
	str = (unsigned char*)src;
	while (n--)
	{
		*(dst)++ = *(str)++;
		if (*(str - 1) == ch)
			return (dst);
	}
	return (NULL);
}
