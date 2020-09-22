/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_numeric_value(const char **format, int (*fun)(int), int symbol)
{
	int		len;
	char	*end;
	char	*res;

	end = (char*)(*format);
	len = 0;
	while (fun(**format))
	{
		(*format)++;
		len++;
	}
	res = (len == 0 ? char_to_string(symbol) : ft_strsub(end, 0, len));
	len = ft_atoi(res);
	free(res);
	return (len);
}

int			print_signs(int times, int sign)
{
	int	tmp;

	tmp = times;
	while (tmp)
	{
		ft_putchar(sign);
		tmp--;
	}
	return (times);
}

int			ft_printf(const char *format, ...)
{
	va_list			ap;
	t_data_format	*data;
	int				res;

	res = 0;
	if (!(data = (t_data_format*)malloc(sizeof(t_data_format))))
		exit(12);
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == PERCENT)
			res += parse_format(&format, data, ap);
		else
		{
			ft_putchar(*format);
			format++;
			res++;
		}
	}
	free(data);
	va_end(ap);
	return (res);
}
