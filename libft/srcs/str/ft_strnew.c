/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:21:21 by dshala            #+#    #+#             */
/*   Updated: 2019/09/16 20:33:12 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tmp;

	if (size == (size_t)-1)
		return (NULL);
	if (!(tmp = (char *)malloc(size + 1)))
		return (NULL);
	tmp[size] = '\0';
	while (size--)
		tmp[size] = '\0';
	return (tmp);
}
