/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:52:35 by nraymond          #+#    #+#             */
/*   Updated: 2024/04/04 18:19:18 by nraymond         ###   ########.fr       */
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
	insert_node(stack_a, pop->val);
	free(pop);
	(*stack_b)->size -= 1;
	update_median(stack_b);
	return (ft_printf("pa\n") != -1);
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
	insert_node(stack_b, pop->val);
	free(pop);
	(*stack_a)->size -= 1;
	update_median(stack_b);
	return (ft_printf("pb\n") != -1);
}

t_elem	*pop_node(t_stack **stack)
{
	t_elem	*pop;

	pop = ((*stack)->head)->prev;
	if (!pop || pop == (*stack)->tail)
		return (NULL);
	return (pop);
}
