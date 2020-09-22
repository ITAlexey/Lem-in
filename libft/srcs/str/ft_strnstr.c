/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:40:18 by dshala            #+#    #+#             */
/*   Updated: 2019/09/16 20:34:34 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *str, char const *find, size_t length)
{
	size_t		i;
	size_t		len;

	if (!*find)
		return ((char*)str);
	len = 0;
	while (str[len] != '\0' && len < length)
	{
		if (str[len] == find[0])
		{
			i = 1;
			while (find[i] != '\0' && str[len + i] == find[i] &&
					(size_t)(len + i) < length)
				++i;
			if (find[i] == '\0')
				return ((char *)&str[len]);
		}
		len++;
	}
	return (0);
}
