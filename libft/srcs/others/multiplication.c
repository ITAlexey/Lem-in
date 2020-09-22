/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplication.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	do_mult(char *a, char *b, char **res)
{
	char		nbr;
	int			index;
	int			i;
	int			j;
	short		flag;

	i = ft_strlen(b) - 1;
	while (i >= 0)
	{
		j = ft_strlen(a) - 1;
		index = i + j + 1;
		flag = 0;
		while (j >= 0)
		{
			nbr = (a[j] - 48) * (b[i] - 48) + ((*res)[index] - 48) + flag;
			flag = nbr / 10;
			(*res)[index--] = (nbr % 10) + 48;
			j--;
		}
		(*res)[index] += flag;
		i--;
	}
	ft_strdel(&a);
	ft_strdel(&b);
}

char		*multiplication(char *a, char *b, unsigned len_a, unsigned len_b)
{
	char		*result;
	char		*tmp;
	unsigned	len;

	if (*a != ZERO && *b != ZERO)
	{
		len = len_a + len_b;
		result = ft_strnew(len + 1);
		ft_memset(result, '0', len);
		if (len_a < len_b)
			swap_str(&a, &b);
		do_mult(a, b, &result);
		if (*result == '0')
		{
			tmp = ft_strdup(result + 1);
			free(result);
			return (tmp);
		}
		return (result);
	}
	ft_strdel(&a);
	ft_strdel(&b);
	return (char_to_string(ZERO));
}
