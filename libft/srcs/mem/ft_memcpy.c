/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:35:37 by dshala            #+#    #+#             */
/*   Updated: 2019/09/16 20:10:09 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t nbr)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*dst;

	if ((!src && !dest) || !nbr)
		return (dest);
	dst = (unsigned char*)dest;
	str = (unsigned char*)src;
	i = 0;
	if (dst == str)
		return (dst);
	while (i < nbr)
	{
		*(dst + i) = *(str + i);
		i++;
	}
	return (dst);
}
