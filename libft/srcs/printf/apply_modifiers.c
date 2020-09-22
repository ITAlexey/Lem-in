/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_modifiers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		put_space_or_zero(char *arg, t_flag *flag, int times)
{
	if (flag->zero)
	{
		print_signs(times, ZERO);
		ft_putstr(arg);
	}
	else
	{
		flag->neg ? ft_putstr(arg) : print_signs(times, SPACE);
		flag->neg ? print_signs(times, SPACE) : ft_putstr(arg);
	}
}

static void		align_ox_by_width(t_data_format *data, t_flag *flag,
				char type, int diff)
{
	if (flag->hash == TRUE && ft_strcmp(data->arg, "0"))
	{
		diff -= type == 'o' ? 1 : 2;
		if (!flag->zero)
			data->arg = add_prefix(data->arg, type == 'x' || type == 'X'
				? "0x" : "0");
		if (flag->zero && (type == 'x' || type == 'X'))
			ft_putstr(type == 'x' ? "0x" : "0X");
		else if (flag->zero)
			ft_putchar(ZERO);
	}
	put_space_or_zero((type == 'X' ? ft_strupcase(data->arg) :
					data->arg), flag, diff);
}

static void		align_dp_by_width(t_data_format *data, t_flag *flag,
				char type, int diff)
{
	int	offset;

	offset = 0;
	if (*(data->arg) != '-' && (flag->space + flag->pos))
	{
		ft_putchar(flag->pos ? PLUS : SPACE);
		diff--;
	}
	if (flag->zero)
	{
		if (*(data->arg) == '-' || type == 'p')
		{
			ft_putstr(type == 'p' ? "0x" : "-");
			offset = type == 'p' ? 2 : 1;
		}
	}
	put_space_or_zero(data->arg + offset, flag, diff);
}

static void		no_char_or_string_type(t_data_format *data,
				t_flag *flag, char type, int diff)
{
	if (ft_strchr("diufp", type))
	{
		if (diff < 0)
			align_dp_by_width(data, flag, type, ABC(diff));
		else
		{
			if (*(data->arg) != '-' && (flag->space + flag->pos))
				data->arg = add_prefix(data->arg, flag->pos ? "+" : " ");
			ft_putstr(data->arg);
		}
	}
	else if (ft_strchr("xXo", type))
	{
		if (diff < 0)
			align_ox_by_width(data, flag, type, ABC(diff));
		else
		{
			if (flag->hash == TRUE && ft_strcmp(data->arg, "0"))
				data->arg = add_prefix(data->arg, type == 'x' || type == 'X' ?
									"0x" : "0");
			ft_putstr(type == 'X' ? ft_strupcase(data->arg) : data->arg);
		}
	}
}

void			apply_modifiers(t_data_format *data, t_flag *flag,
				char type, int width)
{
	int	diff;
	int	len;

	len = (int)ft_strlen(data->arg);
	diff = len - width;
	if (ft_strchr("diufpoXx", type))
		no_char_or_string_type(data, flag, type, diff);
	else
	{
		if (diff < 0)
		{
			diff = ABC(diff);
			flag->neg ? ft_putstr(data->arg) : print_signs(diff, SPACE);
			flag->neg ? print_signs(diff, ZERO) : ft_putstr(data->arg);
		}
		else
			ft_putstr(data->arg);
	}
}
