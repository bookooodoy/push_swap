/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:05:47 by nraymond          #+#    #+#             */
/*   Updated: 2023/11/17 19:36:07 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*to_ret;
	size_t	index;

	index = 0;
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		len = 0;
	to_ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!(to_ret))
		return (NULL);
	while (index < len)
	{
		to_ret[index] = s[start + index];
		index++;
	}
	to_ret[index] = '\0';
	return (to_ret);
}
