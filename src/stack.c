/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:26:42 by nraymond          #+#    #+#             */
/*   Updated: 2024/04/05 16:27:13 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/push_swap.h"
#include "../inc/my-libft/inc/libft.h"

int	insert_node(t_stack **stack, int value)
{
	t_elem	*new_node;
	t_elem	*prev;

	new_node = malloc(sizeof(t_elem));
	if (!new_node)
		return (free_stack(stack), 0);
	prev = (*stack)->head->prev;
	new_node->val = value;
	new_node->next = (*stack)->head;
	new_node->prev = prev;
	prev->next = new_node;
	((*stack)->head)->prev = new_node;
	(*stack)->size += 1;
	update_median(stack);
	return (1);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;
	t_elem	*head;
	t_elem	*tail;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	head = malloc(sizeof(t_elem));
	if (!head)
		return (free(stack), NULL);
	tail = malloc(sizeof(t_elem));
	if (!tail)
	{
		free(head);
		return (free(stack), NULL);
	}
	head->prev = tail;
	head->next = NULL;
	tail->prev = NULL;
	tail->next = head;
	stack->head = head;
	stack->tail = tail;
	stack->size = 0;
	return (stack);
}

int	stack_sorted(t_stack *s)
{
	t_elem	*cur;

	cur = s->head->prev;
	if (!cur || cur == s->tail)
		return (0);
	else if (cur->prev == s->tail)
		return (1);
	while (cur != s->tail->next)
	{
		if (cur->val > cur->prev->val)
			return (0);
		cur = cur->prev;
	}
	return (1);
}

void	solve(t_stack **a, t_stack **b)
{
	sort_first_a(a, b);
	sort_second_b(a, b);
	sort_last_a(a);
	print_stacks(*a, *b);
	free_stack(a);
	free_stack(b);
}
