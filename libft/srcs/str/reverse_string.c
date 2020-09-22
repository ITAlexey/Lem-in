/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:01:42 by dshala            #+#    #+#             */
/*   Updated: 2020/08/16 20:42:39 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*reverse_string(char *str)
{
	size_t	len;
	char	tmp;
	int		i;
	int		j;

	if (str != NULL && *str != '\0')
	{
		len = ft_strlen(str);
		i = 0;
		j = len - 1;
		len >>= 1;
		while (i < (int)len)
		{
			tmp = str[i];
			str[i++] = str[j];
			str[j--] = tmp;
		}
	}
	return (str);
}
