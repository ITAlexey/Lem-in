/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:01:42 by dshala            #+#    #+#             */
/*   Updated: 2020/08/16 20:42:39 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_itoa_len(long long nbr, unsigned int base)
{
	int		len;

	len = nbr < 0 ? 1 : 0;
	while (nbr /= base)
		len++;
	return (++len);
}

char		*ft_itoa_base(long long nbr, unsigned int base)
{
	char	*result;
	char	*str_base;
	short	sign;
	int		len;

	len = get_itoa_len(nbr, base);
	str_base = "0123456789abcdef";
	if (nbr == 0)
		return (char_to_string('0'));
	sign = nbr < 0 ? TRUE : FALSE;
	result = ft_strnew(len);
	ISNULL(result);
	while (nbr)
	{
		result[--len] = str_base[nbr % base];
		nbr /= base;
	}
	if (sign == TRUE)
		result[len] = '-';
	return (result);
}
