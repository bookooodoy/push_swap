/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:17:59 by nraymond          #+#    #+#             */
/*   Updated: 2023/11/16 18:50:35 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t				index;
	unsigned int		size_s;
	unsigned int		size_d;

	size_d = ft_strlen((const char *)dst);
	size_s = ft_strlen(src);
	index = 0;
	if (size_d > size - 1 || size == 0)
		return (size + size_s);
	else
	{
		while (index + size_d < (size - 1) && src[index])
		{
			dst[size_d + index] = src[index];
			index++;
		}
	}
	dst[size_d + index] = '\0';
	return (size_d + size_s);
}
