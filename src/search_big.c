/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_big.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:44:25 by nraymond          #+#    #+#             */
/*   Updated: 2024/04/05 13:29:50 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/push_swap.h"
#include "../inc/my-libft/inc/libft.h"

t_elem	*get_biggest_node(t_stack *s)
{
	t_elem	*cur;
	t_elem	*max;

	cur = s->head->prev;
	if (!cur || cur == s->tail)
		return (NULL);
	max = s->head->prev;
	while (cur && cur != s->tail)
	{
		if (cur->val > max->val)
			max = cur;
		cur = cur->prev;
	}
	return (max);
}


void	set_closest_big(t_elem **closest, t_elem *cur,
	t_elem *node, int *diff_min)
{
	int	diff;

	diff = cur->val - node->val;
	if (diff > 0)
	{
		if (!*diff_min || (*diff_min && diff < *diff_min))
		{
			*closest = cur;
			*diff_min = diff;
		}
	}
	else if (diff < 0 && !*diff_min)
		if (diff > (*closest)->val - node->val)
			*closest = cur;
}

t_elem	*get_closest_node_big(t_elem *node, t_stack *s)
{
	t_elem	*closest;
	t_elem	*cur;
	int		diff_min;

	cur = s->head->prev;
	if (!cur || cur == s->tail)
		return (NULL);
	closest = cur;
	diff_min = 0;
	while (cur && cur != s->tail)
	{
		set_closest_big(&closest, cur, node, &diff_min);
		cur = cur->prev;
	}
	return (closest);
}

t_elem	*find_ideal_position(t_elem *node, t_stack *b)
{
	t_elem	*biggest;
	t_elem	*smallest;
	t_elem	*closest;

	biggest = get_biggest_node(b);
	smallest = get_smallest_node(b);
	if (node->val > biggest->val || node->val < smallest->val)
		return (biggest);
	closest = get_closest_node(node, b);
	return (closest);
}

