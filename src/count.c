/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:51:09 by nraymond          #+#    #+#             */
/*   Updated: 2024/04/04 16:51:21 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/push_swap.h"
#include "../inc/my-libft/inc/libft.h"

int	get_operation_count(t_stack *a, t_stack *b, int ia, int ib)
{
	if (ia < a->median && ib < b->median)
	{
		if (ia > ib)
			return (ia);
		return (ib);
	}
	else if (ia >= a->median && ib >= b->median)
	{
		if (a->size - ia > b->size - ib)
			return (a->size - ia);
		return (b->size - ib);
	}
	return (get_different_count_median(a, b, ia, ib));
}

int	get_number_operations(t_elem *node, t_stack *a, t_stack *b)
{
	t_elem	*inode;
	int		count;
	int		ia;
	int		ib;

	inode = find_ideal_position(node, b);
	ia = get_node_index(node, a);
	ib = get_node_index(inode, b);
	count = get_operation_count(a, b, ia, ib);
	return (count);
}

t_elem	*find_cheapest_node(t_stack *a, t_stack *b)
{
	t_elem	*cur;
	t_elem	*cheapest;
	int		count;
	int		c;

	cur = a->head->prev;
	cheapest = cur;
	count = get_number_operations(cheapest, a, b);
	while (cur && cur != a->tail)
	{
		c = get_number_operations(cur, a, b);
		if (c < count)
		{
			count = c;
			cheapest = cur;
		}
		cur = cur->prev;
	}
	return (cheapest);
}
