/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_suffix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*add_suffix(char *arg, char *pattern)
{
	char *tmp;

	tmp = arg;
	arg = ft_strjoin(arg, pattern);
	ft_strdel(&tmp);
	return (arg);
}
