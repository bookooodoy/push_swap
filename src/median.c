/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:49:33 by nraymond          #+#    #+#             */
/*   Updated: 2024/04/04 16:54:21 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/push_swap.h"
#include "../inc/my-libft/inc/libft.h"

int	get_different_count_median(t_stack *a, t_stack *b, int ia, int ib)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	if (ia < a->median)
		i = ia;
	else if (ia >= a->median)
		i = a->size - ia;
	if (ib < b->median)
		y = ib;
	else if (ib >= b->median)
		y = b->size - ib;
	return (i + y);
}


int	check_difference(int ia, int ib, t_stack *a, t_stack *b)
{
	if (ia < a->median)
	{
		if (ib < b->median)
			return (1);
		else if (ib >= b->median)
			return (ib - ia < b->median);
	}
	else if (ia >= a->median)
	{
		if (ib >= b->median)
			return (2);
		else if (ib < b->median)
			return ((ib + (a->size - ia) >= b->median) + 1);
	}
	return (0);
}
