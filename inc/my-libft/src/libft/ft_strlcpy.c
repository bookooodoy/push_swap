/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:10:00 by nraymond          #+#    #+#             */
/*   Updated: 2023/11/07 17:21:37 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	test;

	index = 0;
	if (size > 0)
	{
		while ((src[index]) && (index < (size - 1)))
		{
			((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
			index++;
		}
		dst[index] = '\0';
	}
	test = ft_strlen(src);
	return (test);
}
