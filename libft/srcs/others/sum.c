/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*align_to_length(char **nbr, unsigned diff)
{
	char		*tmp;
	char		*str_of_zeros;

	str_of_zeros = ft_strnew(diff);
	ISNULL(str_of_zeros);
	ft_memset(str_of_zeros, '0', diff);
	tmp = ft_strjoin(str_of_zeros, *nbr);
	ft_strdel(nbr);
	ft_strdel(&str_of_zeros);
	return (tmp);
}

char		*sum(char *a, char *b, unsigned len_a, unsigned len_b)
{
	int			len;
	int			index;
	char		*result;
	short		flag;
	char		nbr;

	flag = 0;
	index = 0;
	len = MAX(len_a, len_b);
	b = len_a > len_b ? align_to_length(&b, len_a - len_b) : b;
	a = len_a < len_b ? align_to_length(&a, len_b - len_a) : a;
	result = ft_strnew(len + 1);
	ISNULL(result);
	while (len)
	{
		len--;
		nbr = a[len] + b[len] - 96 + flag;
		flag = nbr >= 10 ? 1 : 0;
		result[index++] = flag ? (nbr % 10 + 48) : (nbr + 48);
	}
	result[index] = flag ? '1' : result[index];
	ft_strdel(&a);
	ft_strdel(&b);
	return (reverse_string(result));
}
