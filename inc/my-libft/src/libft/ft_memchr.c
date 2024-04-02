/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:33:25 by nraymond          #+#    #+#             */
/*   Updated: 2023/11/18 13:29:28 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memchr(const void *s, int c, int n)
{
	const char	*b;
	int			index;

	b = s;
	index = 0;
	while (index < n)
	{
		if ((unsigned char)b[index] == (unsigned char)c)
			return ((void *)(s + index));
		index++;
	}
	return ((void *)(0));
}
