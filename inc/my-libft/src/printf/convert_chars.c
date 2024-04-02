/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_chars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 06:40:06 by nraymond          #+#    #+#             */
/*   Updated: 2024/01/30 20:49:09 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_putchar(s[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

char	*convert_c(const char c)
{
	char	*converted;

	converted = malloc(sizeof(char) + 1);
	if (!converted)
		return (NULL);
	converted[0] = c;
	converted[1] = 0;
	return (converted);
}

char	*convert_s(const char *s)
{
	if (!s)
		return (ft_strdup("(null)"));
	return (ft_strdup(s));
}
