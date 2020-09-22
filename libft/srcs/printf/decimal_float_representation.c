/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_float_representation.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	case_of_nine(char **int_part, char **fract_part, int prn)
{
	while ((*fract_part)[prn] == '9')
		(*fract_part)[prn--] = '0';
	if (prn >= 0)
		(*fract_part)[prn]++;
	else
		*int_part = sum(*int_part, ft_strdup("1"), ft_strlen(*int_part), 1);
	return (prn);
}

static void	round_nbr(char **int_part, char **fract_part, int prn)
{
	if (!**fract_part)
	{
		while (prn)
		{
			*fract_part = add_suffix(*fract_part, "0");
			prn--;
		}
	}
	else if (prn == 0)
	{
		*int_part = *fract_part[prn] > '5' ?
			sum(*int_part, ft_strdup("1"), ft_strlen(*int_part), 1) : *int_part;
		(*fract_part)[prn] = 0;
	}
	else if (prn <= (int)ft_strlen(*fract_part))
	{
		case_of_nine(int_part, fract_part, prn);
		(*fract_part)[prn] = 0;
	}
}

static char	*combine_nbr(t_data_format *data, char *int_part,
				char *fract_part, unsigned sign)
{
	char	*result;

	round_nbr(&int_part, &fract_part, data->precision);
	int_part = sign ? add_prefix(int_part, "-") : int_part;
	if (data->flag->hash || data->precision)
		int_part = add_suffix(int_part, ".");
	result = ft_strjoin(int_part, fract_part);
	ft_strdel(&int_part);
	ft_strdel(&fract_part);
	return (result);
}

static char	*convert_int_to_decimal(char **b_mant, int *exp)
{
	char	*decimal_form;
	char	*powered_nbr;

	decimal_form = char_to_string(ZERO);
	while (**b_mant != '\0' && *exp >= 0)
	{
		if (**b_mant == '1')
		{
			powered_nbr = do_power(*exp, 64, powered_value_of_base_two);
			decimal_form = sum(decimal_form, powered_nbr,
					ft_strlen(decimal_form), ft_strlen(powered_nbr));
		}
		(*b_mant)++;
		(*exp)--;
	}
	return (decimal_form);
}

char		*represent_in_decimal_form(t_data_format *data, t_fpoint decimal,
				int exp, char *b_mant)
{
	char	*int_part;
	char	*fraction_part;
	char	*cpy;

	cpy = b_mant;
	int_part = exp < 0 ? char_to_string(ZERO) :
			convert_int_to_decimal(&b_mant, &exp);
	fraction_part = convert_fraction_to_decimal(b_mant, exp);
	ft_strdel(&cpy);
	return (combine_nbr(data, int_part, fraction_part, decimal.field.sign));
}
