/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:01:42 by dshala            #+#    #+#             */
/*   Updated: 2020/08/16 20:42:39 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_uitoa_len(unsigned long long nbr, unsigned int base)
{
	int		len;

	len = 0;
	while (nbr /= base)
		len++;
	return (++len);
}

char		*ft_uitoa_base(unsigned long long nbr, unsigned int base)
{
	char	*result;
	char	*str_base;
	int		len;

	len = get_uitoa_len(nbr, base);
	str_base = "0123456789abcdef";
	if (nbr == 0)
		return (char_to_string('0'));
	result = ft_strnew(len);
	ISNULL(result);
	while (nbr)
	{
		result[--len] = str_base[nbr % base];
		nbr /= base;
	}
	return (result);
}
