/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:52:35 by nraymond          #+#    #+#             */
/*   Updated: 2024/04/05 13:22:24 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/push_swap.h"
#include "../inc/my-libft/inc/libft.h"

int	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_elem	*pop;
	t_elem	*prev;

	pop = pop_node(stack_b);
	if (!pop)
		return (0);
	prev = (*stack_b)->head->prev->prev;
	(*stack_b)->head->prev = prev;
	prev->next = (*stack_b)->head;
	if (!insert_node(stack_a, pop->val))
		return (free(pop), 0);
	(*stack_b)->size -= 1;
	update_median(stack_b);
	return (free(pop), ft_printf("pa\n") == 3);
}

int	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_elem	*pop;
	t_elem	*prev;

	pop = pop_node(stack_a);
	if (!pop)
		return (0);
	prev = (*stack_a)->head->prev->prev;
	(*stack_a)->head->prev = prev;
	prev->next = (*stack_a)->head;
	if (!insert_node(stack_b, pop->val))
		return (free(pop), 0);
	(*stack_a)->size -= 1;
	update_median(stack_b);
	return (free(pop), ft_printf("pb\n") == 3);
}

t_elem	*pop_node(t_stack **stack)
{
	t_elem	*pop;

	pop = ((*stack)->head)->prev;
	if (!pop || pop == (*stack)->tail)
		return (NULL);
	return (pop);
}
