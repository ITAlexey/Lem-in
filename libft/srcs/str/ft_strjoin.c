/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 10:52:42 by dshala            #+#    #+#             */
/*   Updated: 2019/10/01 10:46:01 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*same_str(char const *str)
{
	char	*fresh_str;

	if (!(fresh_str = (char*)malloc(ft_strlen(str) + 1)))
		return (NULL);
	return (ft_strcpy(fresh_str, str));
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s2 != NULL && s1 == NULL)
		return (same_str(s2));
	else if (s1 != NULL && s2 == NULL)
		return (same_str(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = (char*)malloc(len + 1)))
		return (NULL);
	if (len != 0)
	{
		new = ft_memcpy(new, s1, ft_strlen(s1));
		ft_memcpy(new + ft_strlen(s1), s2, ft_strlen(s2));
	}
	new[len] = 0;
	return (new);
}
