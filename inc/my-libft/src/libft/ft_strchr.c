/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:07:31 by nraymond          #+#    #+#             */
/*   Updated: 2023/11/06 17:11:13 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	index;
	size_t	size;

	size = ft_strlen(s);
	index = 0;
	while (index <= size)
	{
		if (s[index] == (char)c)
			return ((char *)s + index);
		index++;
	}
	return ((char *) NULL);
}
