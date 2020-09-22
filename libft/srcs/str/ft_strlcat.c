/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:47:59 by dshala            #+#    #+#             */
/*   Updated: 2019/09/18 18:00:45 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	c;

	i = 0;
	if (dest == NULL && size == 0)
		return (ft_strlen(src));
	while (*(dest + i) != '\0' && i < size)
		i++;
	c = i;
	if (size != 0)
	{
		while (*(src + i - c) && i < size - 1)
		{
			*(dest + i) = *(src + i - c);
			i++;
		}
	}
	if (c < size)
		*(dest + i) = '\0';
	return (c + ft_strlen(src));
}
