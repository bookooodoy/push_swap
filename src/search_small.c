/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:45:33 by nraymond          #+#    #+#             */
/*   Updated: 2024/04/04 16:47:21 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/push_swap.h"
#include "../inc/my-libft/inc/libft.h"

t_elem	*get_smallest_node(t_stack *s)
{
	t_elem	*cur;
	t_elem	*min;

	cur = s->head->prev;
	if (!cur || cur == s->tail)
		return (NULL);
	min = s->head->prev;
	while (cur != s->tail)
	{
		if (cur->val < min->val)
			min = cur;
		cur = cur->prev;
	}
	return (min);
}

void	set_closest(t_elem **closest, t_elem *cur, t_elem *node, int *diff_min)
{
	diff = node->val - cur->val;
	if (diff > 0)
	{
		if (!*diff_min || (*diff_min && diff < *diff_min))
		{
			*closest = cur;
			*diff_min = diff;
		}
	}
	else if (diff < 0 && !*diff_min)
		if (diff > node->val - (*closest)->val)
			*closest = cur;
}

t_elem	*get_closest_node(t_elem *node, t_stack *s)
{
	t_elem	*closest;
	t_elem	*cur;
	int		diff;
	int		diff_min;

	cur = s->head->prev;
	if (!cur || cur == s->tail)
		return (NULL);
	closest = cur;
	diff_min = 0;
	while (cur != s->tail)
	{
		set_closest(&closest, cur, node, &diff_min);
		cur = cur->prev;
	}
	return (closest);
}
