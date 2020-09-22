/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <limits.h>
# include <stdarg.h>
# define PERCENT 37
# define PLUS 43
# define MINUS 45
# define HASH 35
# define SPACE 32
# define ZERO 48
# define DOT 46
# define OFFSET 16383;

typedef enum			e_spec
{
	NONE, L, H, LL, HH, BIGL
}						t_spec;

typedef union			u_fpoint
{
	long double			ld;
	struct
	{
		unsigned long	mantissa : 64;
		unsigned		exp : 15;
		unsigned short	sign : 1;
	}					field;

}						t_fpoint;

typedef struct			s_flag
{
	short				neg;
	short				pos;
	short				zero;
	short				hash;
	short				space;
}						t_flag;

typedef struct			s_data_format
{
	int					percentages;
	t_flag				*flag;
	int					width;
	int					precision;
	t_spec				specifier;
	char				type;
	t_fpoint			decimal;
	char				*arg;
}						t_data_format;

int						ft_printf(char const *format, ...);
int						get_numeric_value(char const **format,
							int (*fun)(int ch), int symbol);
int						print_signs(int times, int sign);
int						parse_format(char const **format, t_data_format *data,
							va_list ap);
t_flag					*get_flags(char const **format);
int						generate_output(t_data_format *data, va_list ap);
char					*parse_type_d(t_spec specifier, va_list ap);
char					*parse_type_u(t_spec specifier, va_list ap);
char					*parse_type_o(t_spec specifier, va_list ap);
char					*parse_type_f(t_data_format *data, t_fpoint decimal,
							t_spec specifier, va_list ap);
char					*represent_in_decimal_form(t_data_format *data,
							t_fpoint decimal, int exp, char *b_mant);
char					*convert_fraction_to_decimal(char *b_fract, int exp);
char					*powered_by_ten(char *nbr, int max_len, int exp);
char					*do_power(int exp, int max_exp, char*(*pow_raise)(int));
char					*powered_value_of_base_two(int exp);
char					*powered_value_of_base_five(int exp);
void					apply_modifiers(t_data_format *data, t_flag *flag,
							char type, int width);

#endif
