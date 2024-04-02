/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_fwidth_buff.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:21:04 by nraymond          #+#    #+#             */
/*   Updated: 2024/01/30 21:14:41 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	prt_spaces(unsigned int lenght)
{
	int	i;

	i = 0;
	while ((unsigned int)i < lenght)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		i++;
	}
	return (i);
}

unsigned int	get_range(char *s)
{
	unsigned int	i;
	unsigned int	range;

	i = 0;
	range = 0;
	if (!s)
		return (0);
	while ((s[i] && is_valid_param(s[i], "# 0-+")))
		i++;
	while (s[i] && ft_isdigit(s[i]))
	{
		range = (10 * range) + (s[i] - '0');
		i++;
	}
	return (range);
}

int	convert_fwidth_negative(t_prt *object, unsigned int lenght)
{
	int	i;

	if (object->cflag == 'c')
	{
		if (ft_putchar(*object->buffer) == -1)
			return (-1);
		i = prt_spaces(object->fwidth - lenght);
	}
	else
	{
		if (ft_putstr(object->buffer) == -1)
			return (-1);
		i = prt_spaces(object->fwidth - lenght);
	}
	if (i == -1)
		return (-1);
	return (i + (int)lenght);
}

int	convert_fwidth_nflag(t_prt *object, unsigned int lenght)
{
	int	i;

	if (object->cflag == 'c')
	{
		i = prt_spaces(object->fwidth - lenght);
		if (ft_putchar(*object->buffer) == -1)
			return (-1);
	}
	else
	{
		i = prt_spaces(object->fwidth - lenght);
		if (ft_putstr(object->buffer) == -1)
			return (-1);
	}
	if (i == -1)
		return (-1);
	return (i + (int)lenght);
}

int	convert_fwidth_buffer(t_prt *object)
{
	unsigned int	lenght;

	lenght = ft_strlen(object->buffer);
	if ((object->fwidth > lenght) || (!*object->buffer))
	{
		if (!*object->buffer && object->cflag == 'c')
			lenght = 1;
		if (object->flags && is_valid_param('-', object->flags))
			return (convert_fwidth_negative(object, lenght));
		else
			return (convert_fwidth_nflag(object, lenght));
	}
	else
		return (ft_putstr(object->buffer));
}
