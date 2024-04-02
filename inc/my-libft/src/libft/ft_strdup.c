/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:11:20 by nraymond          #+#    #+#             */
/*   Updated: 2023/11/09 10:25:02 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	size_t	index;

	index = 0;
	while (src[index])
	{
		((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*duplicate;

	duplicate = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!(duplicate))
		return (NULL);
	duplicate = ft_strcpy(duplicate, s);
	return ((char *)duplicate);
}
