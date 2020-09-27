/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_fraction_to_decimal.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*initialize_nbr(int len, int exp)
{
	int		i;
	char	*init;

	i = 1;
	init = ft_strdup("5");
	ISNULL(init);
	while (i++ < -exp)
		init = multiplication(init, ft_strdup("5"), ft_strlen(init), 1);
	return (powered_by_ten(init, len, exp));
}

static int	get_len(char *b_mant, int exp)
{
	int		len;
	int		cpy;

	cpy = -exp;
	len = 0;
	while (*b_mant != '\0')
	{
		if (*b_mant == '1')
			len = cpy;
		cpy++;
		b_mant++;
	}
	if (len == -exp || len == 0)
		return (-exp);
	return (len + 1);
}

static void	skip_zero_bits(char **b_fract, int *exp)
{
	while (**b_fract == '0')
	{
		(*b_fract)++;
		(*exp)--;
	}
	(*b_fract)++;
}

char		*convert_fraction_to_decimal(char *b_fract, int exp)
{
	char	*decimal_form;
	char	*powered_nbr;
	int		len;

	if (!ft_strchr(b_fract, '1'))
		return (ft_strnew(1));
	if (*b_fract != '\0')
		skip_zero_bits(&b_fract, &exp);
	len = get_len(b_fract, exp);
	decimal_form = initialize_nbr(len, exp--);
	while (*b_fract != '\0')
	{
		if (*b_fract == '1')
		{
			powered_nbr = do_power(ABC(exp), 27, powered_value_of_base_five);
			powered_nbr = powered_by_ten(powered_nbr, len, exp);
			decimal_form = sum(decimal_form, powered_nbr,
						ft_strlen(decimal_form), len);
		}
		exp--;
		b_fract++;
	}
	return (decimal_form);
}
