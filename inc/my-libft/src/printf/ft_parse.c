/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:08:41 by nraymond          #+#    #+#             */
/*   Updated: 2024/01/30 21:47:15 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	is_valid_param(const char c, const char *valid_params)
{
	int	i;

	i = 0;
	if (!valid_params)
		return (0);
	while (valid_params[i])
	{
		if (valid_params[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	get_cflag(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && is_valid_param(s[i], " -+0#"))
		i++;
	if (s[i] == '.')
	{
		i++;
		while (s[i] && ft_isdigit(s[i]))
			i++;
		if (!(is_valid_param(s[i], "cspdiuxX")))
			return (0);
		return (s[i]);
	}
	while (s[i] && ft_isdigit(s[i]))
		i++;
	if (s[i] == '.')
		i++;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	if (!(is_valid_param(s[i], "cspdiuxX%")))
		return (0);
	return (s[i]);
}

char	*get_flags(char *s)
{
	char	*flags;
	int		i;
	int		c;
	size_t	k;

	i = 0;
	c = 0;
	flags = malloc(sizeof(char) * 6);
	if (!flags)
		return (NULL);
	while (s[i] && is_valid_param(s[i], " -+0#"))
	{
		k = i;
		while ((s[++k] && k <= ft_strlen(s))
			&& !is_valid_param(s[k], "cspdiuxX%"))
			if (s[i] != '0' && s[i] == s[k])
				return (free(flags), NULL);
		flags[c++] = s[i++];
	}
	flags[c] = 0;
	if (flags[0] == 0)
		return (free(flags), NULL);
	return (flags);
}

char	*overwrite_flags(char *flags, char ignored)
{
	char	*ov_flags;
	int		i;
	int		c;

	c = 0;
	i = 0;
	if (!flags)
		return (NULL);
	ov_flags = malloc(sizeof(char) * ft_strlen(flags));
	if (!ov_flags)
		return (NULL);
	while (flags[i] && (size_t)c < ft_strlen(flags))
	{
		if (flags[i] != ignored)
			ov_flags[c++] = flags[i];
		i++;
	}
	ov_flags[c] = 0;
	free(flags);
	flags = ov_flags;
	return (flags);
}

char	*parse_legal_flags(char *flags, char cflag)
{
	int	i;

	i = 0;
	if (!cflag || !flags)
		return (NULL);
	while (flags[i])
	{
		if (cflag == 'i' || cflag == 'd' || cflag == 'u')
			if (!is_valid_param(flags[i], "-+ 0"))
				return (free(flags), NULL);
		if (cflag == 'x' || cflag == 'X')
			if (!is_valid_param(flags[i], "-0#"))
				return (free(flags), NULL);
		if (cflag == 'c' || cflag == 's' || cflag == 'p')
			if (!is_valid_param(flags[i], "-"))
				return (free(flags), NULL);
		i++;
	}
	if (is_valid_param('0', flags) && is_valid_param('-', flags))
		flags = overwrite_flags(flags, '0');
	if (is_valid_param('+', flags) && is_valid_param(' ', flags))
		flags = overwrite_flags(flags, ' ');
	return (flags);
}
