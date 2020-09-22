/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:27:50 by dshala            #+#    #+#             */
/*   Updated: 2019/09/16 20:19:08 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int ch, size_t n)
{
	unsigned char	*res;
	size_t			i;

	i = 0;
	res = (unsigned char*)dest;
	while (i < n)
		res[i++] = ch;
	return (res);
}
