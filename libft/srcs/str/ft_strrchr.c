/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:20:46 by dshala            #+#    #+#             */
/*   Updated: 2019/09/16 20:35:26 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	char	to_find;

	tmp = (char *)s;
	to_find = (char)c;
	while (*tmp)
		tmp++;
	if (to_find == '\0')
		return (tmp);
	while (tmp != s && *tmp != to_find)
		tmp--;
	if (*tmp == to_find)
		return (tmp);
	return (NULL);
}
