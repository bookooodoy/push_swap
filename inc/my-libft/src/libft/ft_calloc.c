/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:18:16 by nraymond          #+#    #+#             */
/*   Updated: 2023/11/15 15:16:01 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;

	if ((nmemb == 0) || (size == 0))
		return (malloc(0));
	tab = (char *)malloc(size * nmemb);
	if (!(tab))
		return (NULL);
	ft_bzero(tab, (nmemb * size));
	return ((void *)tab);
}
