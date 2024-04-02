/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 01:30:41 by nraymond          #+#    #+#             */
/*   Updated: 2024/01/30 21:56:25 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

unsigned int	get_uintlen(unsigned int x)
{
	unsigned int	c;

	c = 0;
	while (x > 0)
	{
		x /= 16;
		c++;
	}
	return (c);
}

char	*convert_x(unsigned int x, char *base)
{
	char	*buff;
	size_t	xsize;
	size_t	msize;

	xsize = get_uintlen(x);
	msize = xsize;
	if (x == 0)
		return (ft_strdup("0"));
	buff = malloc(sizeof(char) * xsize + 1);
	if (!buff)
		return (NULL);
	while (x > 0)
	{
		buff[(--xsize)] = base[x % 16];
		x /= 16;
	}
	buff[msize] = 0;
	if (!*buff)
		return (free(buff), NULL);
	return (buff);
}

int	get_plen(void *p)
{
	size_t	psize;
	int		c;

	c = 0;
	psize = ((size_t)p);
	if (psize == (size_t) NULL)
		return (0);
	while (psize > 0)
	{
		psize /= 16;
		c++;
	}
	return (c + 2);
}

char	*convert_arg_p(void *p, char *base)
{
	char		*buff;
	size_t		psize;
	size_t		csize;
	int			i;

	i = 0;
	psize = (size_t)get_plen(p);
	csize = (size_t)p;
	if (!psize)
		return (ft_strdup("(nil)"));
	buff = malloc(sizeof(char) * psize + 1);
	if (!buff)
		return (NULL);
	while (csize > 0)
	{
		if (i == 0)
		{
			buff[i++] = '0';
			buff[i++] = 'x';
		}
		buff[(psize + 1) - i++] = base[csize % 16];
		csize /= 16;
	}
	buff[i] = 0;
	return (buff);
}
