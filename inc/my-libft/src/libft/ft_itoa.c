/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:55:50 by nraymond          #+#    #+#             */
/*   Updated: 2023/11/17 16:16:44 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	count_digit_length(int n)
{
	size_t	length;
	size_t	popo;

	length = 1;
	popo = (size_t)n;
	if (n < 0)
	{
		length++;
		popo = (size_t)n * -1;
	}
	while (popo >= 10)
	{
		length++;
		popo /= 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*crazy;
	int		d;
	size_t	popo;

	d = count_digit_length(n);
	crazy = (char *)malloc(sizeof(char) * (d + 1));
	if (!crazy)
		return (NULL);
	if (n == 0)
		crazy[0] = '0';
	popo = (size_t)n;
	if (n < 0)
	{
		crazy[0] = '-';
		popo = (size_t)n * -1;
	}
	crazy[d--] = '\0';
	while (popo != 0)
	{
		crazy[d--] = (popo % 10) + '0';
		popo /= 10;
	}
	return (crazy);
}
