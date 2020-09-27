/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hashcode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		get_hashcode(const char *str)
{
	unsigned int	hashcode;

	hashcode = 5381;
	while (*str != '\0')
	{
		hashcode = (hashcode << 5) + hashcode + *str;
		str++;
	}
	return (hashcode);
}
