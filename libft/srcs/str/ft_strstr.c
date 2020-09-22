/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:07:27 by dshala            #+#    #+#             */
/*   Updated: 2019/09/16 20:40:33 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	char	*word;
	size_t	c;
	size_t	i;

	i = 0;
	word = (char*)str1;
	if (*str2 == '\0')
		return (word);
	if (*str1 == '\0')
	{
		if (*str2 == '\0')
			return (word);
		return (NULL);
	}
	while (*(str1 + i))
	{
		c = ft_strlen(str2);
		if (*(str1 + i) == str2[c - c])
			if (ft_strncmp(str1 + i, str2, c) == 0)
				return (&word[i]);
		i++;
	}
	return (NULL);
}
