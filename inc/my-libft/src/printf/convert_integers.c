/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_integers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 06:52:21 by nraymond          #+#    #+#             */
/*   Updated: 2024/01/30 21:21:29 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	count_digit_length(unsigned int n)
{
	size_t	length;
	size_t	num;

	length = 1;
	num = n;
	while (num >= 10)
	{
		length++;
		num /= 10;
	}
	return (length);
}

char	*ft_uitoa(unsigned int n)
{
	char	*converted;
	size_t	d;
	size_t	num;

	d = count_digit_length(n);
	converted = (char *)malloc(sizeof(char) * (d + 1));
	if (!converted)
		return (NULL);
	if (n == 0)
		converted[0] = '0';
	converted[d--] = 0;
	num = n;
	while (num != 0)
	{
		converted[d--] = (num % 10) + '0';
		num /= 10;
	}
	return (converted);
}

char	*convert_d_i(int i)
{
	char	*converted;

	converted = ft_itoa(i);
	if (!converted)
		return (NULL);
	return (converted);
}
