/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:27:26 by dshala            #+#    #+#             */
/*   Updated: 2019/09/14 20:57:02 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		ch;

	ch = (unsigned char)c;
	str = (const unsigned char*)arr;
	while (n--)
	{
		if (*str++ == ch)
			return ((void*)(str - 1));
	}
	return (NULL);
}
