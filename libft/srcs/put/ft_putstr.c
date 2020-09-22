/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:16:19 by dshala            #+#    #+#             */
/*   Updated: 2019/09/16 21:41:52 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *str)
{
	size_t	len;
	char	*tmp;

	if (!str)
		return ;
	tmp = (char*)str;
	len = 0;
	while (tmp[len] != '\0')
		write(1, &tmp[len++], 1);
}
