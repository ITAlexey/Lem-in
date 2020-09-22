/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:15:26 by dshala            #+#    #+#             */
/*   Updated: 2019/09/16 20:43:08 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	a;
	size_t	b;
	size_t	c;
	size_t	d;

	if (!s)
		return (NULL);
	a = ft_strlen(s);
	b = 0;
	c = 0;
	while ((s[b] == ' ' || s[b] == '\n' || s[b] == '\t'))
		b++;
	if (a == b)
		return (ft_strsub(s, a, 1));
	d = a - 1;
	while ((s[d - c] == ' ' || s[d - c] == '\n' || s[d - c] == '\t'))
		c++;
	return (ft_strsub(s, b, a - b - c));
}
