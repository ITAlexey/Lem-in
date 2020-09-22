/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		record_flag(short *value)
{
	*value = TRUE;
	return (TRUE);
}

static int		is_matched_to_flag(char ch, t_flag *flag)
{
	if (ch == PLUS)
		return (record_flag(&(flag->pos)));
	else if (ch == MINUS)
		return (record_flag(&(flag->neg)));
	else if (ch == SPACE)
		return (record_flag(&(flag->space)));
	else if (ch == ZERO)
		return (record_flag(&(flag->zero)));
	else if (ch == HASH)
		return (record_flag(&(flag->hash)));
	else
		return (FALSE);
}

static void		init(t_flag *tmp)
{
	tmp->pos = FALSE;
	tmp->neg = FALSE;
	tmp->hash = FALSE;
	tmp->zero = FALSE;
	tmp->space = FALSE;
}

t_flag			*get_flags(char const **format)
{
	t_flag	*tmp;

	tmp = (t_flag*)malloc(sizeof(t_flag));
	if (tmp == NULL)
		exit(12);
	init(tmp);
	while (is_matched_to_flag(**format, tmp))
		(*format)++;
	return (tmp);
}
