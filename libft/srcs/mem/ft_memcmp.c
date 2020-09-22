/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:05:33 by dshala            #+#    #+#             */
/*   Updated: 2019/09/12 18:47:10 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	if (!count)
		return (0);
	while (--count && *(char*)buf1 == *(char*)buf2)
	{
		buf1 = (char*)buf1 + 1;
		buf2 = (char*)buf2 + 1;
	}
	return (*((unsigned char*)buf1) - *((unsigned char*)buf2));
}
