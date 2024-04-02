/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:01:29 by nraymond          #+#    #+#             */
/*   Updated: 2023/11/18 13:45:57 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	k;

	index = 0;
	if (ft_strlen(little) == 0 || little == big)
		return ((char *)big);
	if (len <= 0 || (ft_strlen(little) > ft_strlen(big))
		|| ft_strlen(little) > len)
		return (NULL);
	while (big[index] && index <= len)
	{
		if (big[index] == little[0])
		{
			k = -1;
			while (++k < ft_strlen(little) && (k + index < len))
				if (big[k + index] != little[k])
					break ;
			if (k == ft_strlen(little))
				return ((char *) big + index);
		}
		index++;
	}
	return (NULL);
}
