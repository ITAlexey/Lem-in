/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 20:35:31 by dshala            #+#    #+#             */
/*   Updated: 2019/10/01 10:39:44 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *src)
{
	unsigned char			*temp;
	unsigned long			i;
	unsigned const char		*str;

	i = 0;
	str = (unsigned char*)src;
	if (src == NULL || !(temp = (unsigned char*)malloc(ft_strlen(src) + 1)))
		return (NULL);
	while (str[i] != 0)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return ((char*)temp);
}
