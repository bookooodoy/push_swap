/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:33:01 by nraymond          #+#    #+#             */
/*   Updated: 2024/04/04 18:13:32 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/push_swap.h"
#include "../inc/my-libft/inc/libft.h"

void	put_to_top(t_elem *target_a, t_elem *target_b, t_stack *a, t_stack *b)
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
			rr(&a, &b);
		else if (check_difference(ia, ib, a, b) == 2
			&& (a->head->prev->val != va && b->head->prev->val != vb))
			rrr(&a, &b);
		else
		{
			if (ia < a->median && a->head->prev->val != va)
				rotate_up(&a, 1);
			else if (ia >= a->median && a->head->prev->val != va)
				rotate_down(&a, 1);
			if (ib < b->median && b->head->prev->val != vb)
				rotate_up(&b, 0);
			else if (ib >= b->median && b->head->prev->val != vb)
				rotate_down(&b, 0);
		}
	}
}

void	sort_three(t_stack *s)
{
	if (s->size > 2)
	{
		if ((s->head->prev->prev)->val > (s->tail->next)->val
			&& (s->head->prev->prev)->val > (s->head->prev)->val)
			rotate_down(&s, 1);
		else if ((s->head->prev)->val > (s->head->prev->prev)->val
			&& (s->head->prev)->val > (s->tail->next)->val)
			rotate_up(&s, 1);
	}
	if ((s->head->prev)->val > (s->head->prev->prev)->val)
		swap_a(&s);
}

void	sort_first_a(t_stack **a, t_stack **b)
{
	t_elem	*cheapest;
	t_elem	*ideal;

	if (stack_sorted(*a))
		return ;
	if ((*a)->size <= 3)
	{
		sort_three(*a);
		return ;
	}
	push_b(a, b);
	push_b(a, b);
	while ((*a)->size > 3)
	{
		cheapest = find_cheapest_node(*a, *b);
		ideal = find_ideal_position(cheapest, *b);
		put_to_top(cheapest, ideal, *a, *b);
		push_b(a, b);
	}
	sort_three(*a);
}

void	sort_second_b(t_stack **a, t_stack **b)
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
			push_a(a, b);
		}
		else
		{
			put_to_top(ideal, cheapest, *a, *b);
			push_a(a, b);
		}
	}
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
			rotate_up(a, 1);
		else
			rotate_down(a, 1);
	}
}
