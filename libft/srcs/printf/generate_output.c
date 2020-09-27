/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#define NULLSTR "(null)"

static char	*parse_type_s(char *str)
{
	return (ft_strdup(str == NULL ? NULLSTR : str));
}

static char	*retrieve_according_type(t_data_format *data, va_list ap)
{
	if (data->type == 'd' || data->type == 'i')
		return (parse_type_d(data->specifier, ap));
	else if (data->type == 'p')
		return (add_prefix(ft_itoa_base((long long)va_arg(ap, void *), 16),
								"0x"));
	else if (data->type == 'o')
		return (parse_type_o(data->specifier, ap));
	else if (data->type == 'u')
		return (parse_type_u(data->specifier, ap));
	else if (data->type == 'x')
		return (ft_itoa_base(va_arg(ap, long long), 16));
	else if (data->type == 'X')
		return (ft_itoa_base(va_arg(ap, long long), 16));
	else if (data->type == 'c')
		return (char_to_string(va_arg(ap, int)));
	else if (data->type == 's')
		return (parse_type_s(va_arg(ap, char*)));
	else if (data->type == 'f')
		return (parse_type_f(data, data->decimal, data->specifier, ap));
	else
		return (NULL);
}

int			generate_output(t_data_format *data, va_list ap)
{
	int result;

	result = 0;
	if (data->type != '\0')
	{
		data->arg = retrieve_according_type(data, ap);
		apply_modifiers(data, data->flag, data->type, data->width);
		result = MAX(data->width, (int)ft_strlen(data->arg));
		free(data->arg);
	}
	free(data->flag);
	return (print_signs(data->percentages / 2, PERCENT) + result);
}
