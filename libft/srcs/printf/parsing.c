/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define TYPE_PATTERN "cspdiouxXf"

static int			get_nbr_of_percentages(char const **format)
{
	int		percent_counter;

	percent_counter = 0;
	while (**format == PERCENT)
	{
		percent_counter++;
		(*format)++;
	}
	return (percent_counter);
}

static t_spec		get_specifier(char const **format)
{
	t_spec	specifier;

	specifier = NONE;
	if (**format == 'l' || **format == 'h' || **format == 'L')
	{
		if (**format == 'l' && *(*format + 1) == 'l')
			specifier = LL;
		else if (**format == 'h' && *(*format + 1) == 'h')
			specifier = HH;
		else if (**format == 'l')
			specifier = L;
		else if (**format == 'h')
			specifier = H;
		else
			specifier = BIGL;
		*format += specifier == HH || specifier == LL ? 2 : 1;
	}
	return (specifier);
}

static char			get_type(char const **format, char *pattern)
{
	while (*pattern != '\0')
	{
		if (**format == *pattern)
		{
			(*format)++;
			break ;
		}
		pattern++;
	}
	return (*pattern);
}

static int			get_precision(char const **format)
{
	short	is_dot;

	is_dot = **format == DOT ? 1 : 0;
	if (is_dot)
		(*format)++;
	return (is_dot ? get_numeric_value(format, ft_isdigit, ZERO) : 6);
}

int					parse_format(char const **format, t_data_format *data,
				va_list ap)
{
	data->percentages = get_nbr_of_percentages(format);
	if (data->percentages % 2 != 0)
	{
		data->flag = get_flags(format);
		data->width = get_numeric_value(format, ft_isdigit, ZERO);
		data->precision = get_precision(format);
		data->specifier = get_specifier(format);
		data->type = get_type(format, TYPE_PATTERN);
	}
	return (generate_output(data, ap));
}
