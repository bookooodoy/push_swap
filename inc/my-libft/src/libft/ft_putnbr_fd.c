/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:34:56 by nraymond          #+#    #+#             */
/*   Updated: 2023/11/17 14:19:32 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb2;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	nb2 = n;
	if (nb2 >= 10)
	{
		ft_putnbr_fd(nb2 / 10, fd);
		nb2 %= 10;
	}
	ft_putchar_fd(nb2 + '0', fd);
}
