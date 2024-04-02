/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:46:19 by nraymond          #+#    #+#             */
/*   Updated: 2023/11/10 15:04:29 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*run;
	size_t			index;

	run = s;
	index = 0;
	while (index < n)
	{
		run[index] = (unsigned char)c;
		index++;
	}
	return ((void *)run);
}
