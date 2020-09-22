/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:35:57 by dshala            #+#    #+#             */
/*   Updated: 2019/09/15 16:31:07 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char const *src, size_t n)
{
	char	*cpy;

	cpy = dest;
	while (*cpy)
		cpy++;
	while (n > 0 && *src)
	{
		*cpy++ = *src++;
		n--;
	}
	*cpy = '\0';
	return (dest);
}
