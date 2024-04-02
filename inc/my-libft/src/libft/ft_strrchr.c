/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:57:27 by nraymond          #+#    #+#             */
/*   Updated: 2023/11/17 19:59:02 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;
	size_t	size;

	size = ft_strlen(s);
	index = 0;
	while (index <= size)
	{
		if (s[size - index] == (char)c)
			return ((char *)s + (size - index));
		index++;
	}
	return ((char *) NULL);
}
