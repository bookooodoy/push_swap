/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:34:50 by nraymond          #+#    #+#             */
/*   Updated: 2023/11/09 12:30:48 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_memcmp(const void *s1, const void *s2, int n)
{
	int					index;
	unsigned const char	*first;
	unsigned const char	*last;

	index = 0;
	if (n <= 0)
		return (0);
	first = (unsigned const char *)s1;
	last = (unsigned const char *)s2;
	while (index < n - 1)
	{
		if (first[index] != last[index])
			return ((int )first[index] - last[index]);
		index++;
	}
	return ((int)first[index] - last[index]);
}
