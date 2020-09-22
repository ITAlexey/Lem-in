/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_to_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define NEG 1
#define POS 0

static char		*nbrcpy(char *dest, long long nbr, int len)
{
	short	sign;

	sign = nbr < 0 ? NEG : POS;
	nbr = ABC(nbr);
	while (nbr != 0)
	{
		dest[len--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (sign == NEG)
		dest[len] = '-';
	return (dest);
}

char			*nbr_to_string(long long nbr)
{
	int			len;
	char		*str;

	if (nbr == 0)
		return (char_to_string('0'));
	len = ft_nbrlen(nbr);
	str = (char*)malloc(len + 1);
	ISNULL(str);
	str[len] = '\0';
	return (nbrcpy(str, nbr, len - 1));
}
