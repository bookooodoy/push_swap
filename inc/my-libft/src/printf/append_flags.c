/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:30:59 by nraymond          #+#    #+#             */
/*   Updated: 2024/01/30 04:40:46 by bookoodoy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	append_hashtag(t_prt *object)
{
	char	*new_buff;

	if (object->cflag == 'x')
		new_buff = ft_strjoin("0x", object->buffer);
	else if (object->cflag == 'X')
		new_buff = ft_strjoin("0X", object->buffer);
	else
		return ;
	free(object->buffer);
	object->buffer = new_buff;
}

void	append_plus(char **buffer)
{
	char	*new_buff;

	new_buff = ft_strjoin("+", *buffer);
	free(*buffer);
	*buffer = new_buff;
}

void	append_space(char **buffer)
{
	char	*new_buff;

	if (ft_atoi(*buffer) >= 0 || *buffer[0] == 0)
		new_buff = ft_strjoin(" ", *buffer);
	else
		return ;
	free(*buffer);
	*buffer = new_buff;
}

void	append_zeroes(size_t bufferlen, char **buffer, int fwidth)
{
	char	*new_buff;
	char	*bzeroes;

	if (bufferlen < ((size_t) fwidth))
	{
		bzeroes = malloc(sizeof(char) * (fwidth + 2));
		if (!bzeroes)
			return ;
		if (*buffer[0] == '-')
		{
			ft_memset(bzeroes, '0', fwidth - bufferlen + 1);
			bzeroes[0] = '-';
			bzeroes[fwidth - bufferlen + 1] = 0;
			new_buff = ft_strjoin(bzeroes, *buffer + 1);
		}
		else
		{
			ft_memset(bzeroes, '0', fwidth - bufferlen);
			bzeroes[fwidth - bufferlen] = 0;
			new_buff = ft_strjoin(bzeroes, *buffer);
		}
		free(*buffer);
		free(bzeroes);
		*buffer = new_buff;
	}
}

void	append_flags(t_prt *object)
{
	if ((is_valid_param(object->cflag, "xX") && is_valid_param
			('#', object->flags)) && !is_zero(object->buffer))
		append_hashtag(object);
	if (object->buffer && object->flags && is_valid_param
		(object->cflag, "diu") && is_valid_param
		('+', object->flags) && ft_atoi(object->buffer) >= 0)
		append_plus(&(object->buffer));
	if (object->buffer && object->flags && is_valid_param
		(object->cflag, "dius") && is_valid_param(' ', object->flags))
		append_space(&(object->buffer));
	if (object->buffer && object->flags && object->fwidth
		&& (object->precision == -1) && is_valid_param
		(object->cflag, "diuxX") && is_valid_param('0', object->flags))
		append_zeroes(ft_strlen(object->buffer),
			&(object->buffer), (object->fwidth));
}
