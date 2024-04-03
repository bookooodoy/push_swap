/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:34:54 by nraymond          #+#    #+#             */
/*   Updated: 2023/11/10 15:36:37 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	if (!s)
		return (0);
	while (s[index] != '\0')
		index++;
	return (index);
}
