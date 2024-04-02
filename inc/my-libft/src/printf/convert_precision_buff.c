/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_precision_buff.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:31:07 by nraymond          #+#    #+#             */
/*   Updated: 2024/01/30 21:51:52 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	is_zero(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i] && buf[i] == '0')
		i++;
	return (i == ft_strlen(buf));
}

int	get_precision(char *s)
{
	int	precision;
	int	i;

	precision = 0;
	i = 0;
	if (!s)
		return (-1);
	while (s[i] && s[i] != '.')
	{
		if (is_valid_param(s[i], "cspdiuxX%"))
			return (-1);
		i++;
	}
	if (s[i] != '.')
		return (-1);
	++i;
	while (s[i] && ft_isdigit(s[i]))
	{
		precision = (10 * precision) + (s[i] - '0');
		i++;
	}
	return (precision);
}

char	*convert_from_flag(char cflag, va_list vargs)
{
	if (is_valid_param(cflag, "diu"))
	{
		if (cflag == 'u')
			return (ft_uitoa(va_arg(vargs, unsigned int)));
		return (convert_d_i(va_arg(vargs, int)));
	}
	if (cflag == 's')
		return (convert_s(va_arg(vargs, char *)));
	if (cflag == 'c')
		return (convert_c(va_arg(vargs, int)));
	if (cflag == 'p')
		return (convert_arg_p(va_arg(vargs, void *), "0123456789abcdef"));
	if (cflag == 'x')
		return (convert_x(va_arg(vargs, unsigned int), "0123456789abcdef"));
	if (cflag == 'X')
		return (convert_x(va_arg(vargs, unsigned int), "0123456789ABCDEF"));
	return (NULL);
}

void	convert_precision_buffer_sflag(t_prt *object)
{
	char	*new_buff;

	if (ft_strlen(object->buffer) > (size_t)object->precision)
	{
		new_buff = ft_substr(object->buffer, 0, (size_t)object->precision);
		free(object->buffer);
		object->buffer = new_buff;
	}
}

void	convert_precision_buffer(t_prt *object)
{
	if (object->buffer && object->precision != -1)
	{
		if (is_valid_param(object->cflag, "diuxX"))
		{
			if (object->buffer[0] == '-')
				append_zeroes(ft_strlen(object->buffer) - 1,
					&(object->buffer), object->precision);
			else if (is_zero(object->buffer) && object->precision == 0)
				object->buffer[0] = 0;
			else
				append_zeroes(ft_strlen(object->buffer),
					&(object->buffer), object->precision);
		}
		else if (is_valid_param(object->cflag, "s"))
			convert_precision_buffer_sflag(object);
	}
}
