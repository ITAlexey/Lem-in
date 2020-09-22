/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenonat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:23:26 by avenonat          #+#    #+#             */
/*   Updated: 2019/09/16 15:17:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_LONG 9223372036854775807

int			ft_atoi(const char *str)
{
	unsigned long long		nmbr;
	char					ch;

	nmbr = 0;
	while ((*str < 14 && *str > 8) || *str == 32)
		str++;
	ch = '+';
	if (*str == '-' || *str == '+')
	{
		ch = *str;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		nmbr = nmbr * 10 + (*str - '0');
		str++;
	}
	if (nmbr > MAX_LONG)
		return (ch == '-' ? 0 : -1);
	return (ch == '-' ? -nmbr : nmbr);
}
