/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:33:01 by nraymond          #+#    #+#             */
/*   Updated: 2024/04/05 13:55:44 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/push_swap.h"
#include "../inc/my-libft/inc/libft.h"

int	put_to_top(t_elem *target_a, t_elem *target_b, t_stack *a, t_stack *b)
{
	int	ia;
	int	ib;
	int	va;
	int	vb;

	ia = get_node_index(target_a, a);
	ib = get_node_index(target_b, b);
	va = target_a->val;
	vb = target_b->val;
	while (a->head->prev->val != va || b->head->prev->val != vb)
	{
		if (check_difference(ia, ib, a, b) == 1
			&& (a->head->prev->val != va && b->head->prev->val != vb))
		{
			if (!rr(&a, &b))
				return (0);
		}
		else if (check_difference(ia, ib, a, b) == 2
			&& (a->head->prev->val != va && b->head->prev->val != vb))
		{
			if (!rrr(&a, &b))
				return (0);
		}
		else
		{
			if (ia < a->median && a->head->prev->val != va)
			{
				if (!rotate_up(&a, 1))
					return (0);
			}
			else if (ia >= a->median && a->head->prev->val != va)
			{
				if (!rotate_down(&a, 1))
					return (0);
			}
			if (ib < b->median && b->head->prev->val != vb)
			{
				if (!rotate_up(&b, 0))
					return (0);
			}
			else if (ib >= b->median && b->head->prev->val != vb)
			{
				if (!rotate_down(&b, 0))
					return (0);
			}
		}
	}
	return (1);
}

int	sort_three(t_stack *s)
{
	if (s->head->prev == s->tail || s->head->prev->prev == s->tail)
		return (0);
	if (s->size > 2)
	{
		if ((s->head->prev->prev)->val > (s->tail->next)->val
			&& (s->head->prev->prev)->val > (s->head->prev)->val)
		{
			if (!rotate_down(&s, 1))
				return (0);
		}
		else if ((s->head->prev)->val > (s->head->prev->prev)->val
			&& (s->head->prev)->val > (s->tail->next)->val)
		{
			if (!rotate_up(&s, 1))
				return (0);
		}
	}
	else if (s->size >= 2 && (s->head->prev->val) > (s->head->prev->prev)->val)
	{
		if (!swap_a(&s))
			return (0);
	}
	return (s->size > 2);
}

int	sort_first_a(t_stack **a, t_stack **b)
{
	t_elem	*cheapest;
	t_elem	*ideal;

	if (stack_sorted(*a))
		return (0);
	if ((*a)->size <= 3)
		return (sort_three(*a));
	if (!push_b(a, b))
		return (0);
	if (!push_b(a, b))
		return (0);
	while ((*a)->size > 3)
	{
		cheapest = find_cheapest_node(*a, *b);
		ideal = find_ideal_position(cheapest, *b);
		put_to_top(cheapest, ideal, *a, *b);
		push_b(a, b);
	}
	return (sort_three(*a));
}

int	sort_second_b(t_stack **a, t_stack **b)
{
	t_elem	*cheapest;
	t_elem	*ideal;

	while ((*b)->head->prev != (*b)->tail)
	{
		cheapest = (*b)->head->prev;
		ideal = get_closest_node_big(cheapest, *a);
		if (get_biggest_node(*a)->val < cheapest->val)
		{
			put_to_top(get_smallest_node(*a), cheapest, *a, *b);
			if (!push_a(a, b))
				return (0);
		}
		else
		{
			put_to_top(ideal, cheapest, *a, *b);
			if (!push_a(a, b))
				return (0);
		}
	}
	return (1);
}

void	sort_last_a(t_stack **a)
{
	t_elem	*min;
	int		is_half;
	int		val;

	min = get_smallest_node(*a);
	is_half = get_node_index(min, *a) < (*a)->median;
	val = min->val;
	while ((*a)->head->prev->val != val)
	{
		if (is_half)
		{
			if (!rotate_up(a, 1))
				return ;
		}
		else
		{
			if (!rotate_down(a, 1))
				return ;
		}
	}
}
