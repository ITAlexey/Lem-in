/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2019/09/16 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define IN 1
#define OUT 0

size_t		ft_count_words(const char *str, int c)
{
	size_t	counter;
	int		is_word;

	is_word = OUT;
	counter = 0;
	if (str != NULL)
	{
		while (*str != '\0')
		{
			if (*str != c && is_word == OUT)
			{
				counter++;
				is_word = IN;
			}
			else if (*str == c && is_word == IN)
				is_word = OUT;
			str++;
		}
	}
	return (counter);
}
