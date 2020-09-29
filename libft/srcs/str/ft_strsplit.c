/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:51:15 by dshala            #+#    #+#             */
/*   Updated: 2019/09/19 12:54:43 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define IN 1
#define OUT 0

static char			**free_splitted_str(char **str, long pos)
{
	while (pos >= 0)
		free(str[pos--]);
	free(str);
	str = NULL;
	return (str);
}

static int			counter(char const *str, int dil, short to_skip)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (to_skip ? str[i] == dil : str[i] != dil))
		i++;
	return (i);
}

char				**ft_strsplit(char const *str, char c)
{
	int		words;
	int		i;
	char	**splitted_str;
	int		letters;

	i = 0;
	if (str == NULL)
		return (NULL);
	words = ft_count_words(str, c);
	if (!(splitted_str = (char**)ft_memalloc(sizeof(char*) * (words + 1))))
		return (NULL);
	splitted_str[words] = NULL;
	while (*str != '\0' && i < words)
	{
		str += counter(str, c, 1);
		letters = counter(str, c, 0);
		if (!(splitted_str[i] = ft_strsub(str, 0, letters)))
			return (free_splitted_str(splitted_str, i));
		str += letters;
		i++;
	}
	return (splitted_str);
}
