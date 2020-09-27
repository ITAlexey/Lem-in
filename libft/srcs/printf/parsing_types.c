/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*is_inf_or_nan(long double ld)
{
	if (ld != ld)
		return (ft_strdup("nan"));
	else if (ld == -(1.0 / 0.0))
		return (ft_strdup("-inf"));
	else if (ld == (1.0 / 0.0))
		return (ft_strdup("inf"));
	return (ft_strdup("(null)"));
}

char		*parse_type_f(t_data_format *data, t_fpoint decimal,
					t_spec specifier, va_list ap)
{
	char	*binary_mantissa;
	int		exp;

	decimal.ld = specifier == BIGL ? va_arg(ap, long double) :
	(double)va_arg(ap, double);
	if ((decimal.field.exp == SHRT_MAX && decimal.field.mantissa > LONG_MAX)
		|| decimal.ld != decimal.ld)
		return (is_inf_or_nan(decimal.ld));
	exp = decimal.field.exp - OFFSET;
	binary_mantissa = ft_uitoa_base(decimal.field.mantissa, 2);
	return (represent_in_decimal_form(data, decimal, exp, binary_mantissa));
}

char		*parse_type_u(t_spec specifier, va_list ap)
{
	if (specifier == L)
		return (ft_uitoa_base((unsigned long)va_arg(ap, unsigned long), 10));
	else if (specifier == H)
		return (ft_uitoa_base((unsigned short)va_arg(ap, unsigned int), 10));
	else if (specifier == LL)
		return (nbr_to_string((long long)va_arg(ap, long long)));
	else if (specifier == HH)
		return (ft_uitoa_base((unsigned char)va_arg(ap, int), 10));
	return (ft_uitoa_base(va_arg(ap, unsigned), 10));
}

char		*parse_type_d(t_spec specifier, va_list ap)
{
	if (specifier == L)
		return (nbr_to_string((long)va_arg(ap, long)));
	else if (specifier == H)
		return (nbr_to_string((short)va_arg(ap, int)));
	else if (specifier == LL)
		return (nbr_to_string((long long)va_arg(ap, long long)));
	else if (specifier == HH)
		return (nbr_to_string((char)va_arg(ap, int)));
	return (nbr_to_string((long long)va_arg(ap, int)));
}

char		*parse_type_o(t_spec specifier, va_list ap)
{
	if (specifier == L)
		return (ft_uitoa_base((long)va_arg(ap, long), 8));
	else if (specifier == H)
		return (ft_uitoa_base((unsigned short)va_arg(ap, unsigned), 8));
	else if (specifier == LL)
		return (ft_uitoa_base((long long)va_arg(ap, long long), 8));
	else if (specifier == HH)
		return (ft_uitoa_base(va_arg(ap, int), 8));
	return (ft_uitoa_base((unsigned long long)va_arg(ap, unsigned), 8));
}
