/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:52:06 by nraymond          #+#    #+#             */
/*   Updated: 2024/04/04 14:54:36 by nraymond         ###   ########.fr       */
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
	tail = malloc(sizeof(t_elem));
	if (!tail || !head)
	{
		free(head);
		free(stack);
		return (free(tail), NULL);
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

void	swap_nodes(t_stack **stack)
{
	t_elem	*prev;
	int		temp_val;

	prev = ((*stack)->head)->prev;
	if (!prev || (prev == (*stack)->tail) || prev->prev == (*stack)->tail)
		return ;
	temp_val = prev->prev->val;
	prev->prev->val = prev->val;
	prev->val = temp_val;
}

int	swap_a(t_stack **stack_a)
{
	swap_nodes(stack_a);
	return (ft_printf("sa\n") != -1);
}

int	swap_b(t_stack **stack_b)
{
	swap_nodes(stack_b);
	return (ft_printf("sb\n") != -1);
}

int	swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_nodes(stack_a);
	swap_nodes(stack_b);
	return (ft_printf("ss\n") != -1);
}

