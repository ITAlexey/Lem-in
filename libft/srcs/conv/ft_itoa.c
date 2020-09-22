/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:18:53 by dshala            #+#    #+#             */
/*   Updated: 2019/09/15 20:24:20 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MIN_INT -2147483648

static size_t		ft_digit_len(int nbr)
{
	size_t	i;

	i = 1;
	while (nbr / 10)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	char	*str;
	size_t	nlen;
	int		flag;

	flag = (n < 0 ? 1 : 0);
	nlen = ft_digit_len(ABC(n));
	if (flag == 1)
		nlen++;
	if (n == MIN_INT)
		return (ft_strdup("-2147483648"));
	if (!(str = ft_strnew(nlen)))
		return (NULL);
	while (nlen--)
	{
		str[nlen] = (n % 10) + '0';
		n = n / 10;
	}
	if (flag == 1)
		str[0] = '-';
	return (str);
}
