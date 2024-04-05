/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:54:46 by nraymond          #+#    #+#             */
/*   Updated: 2024/04/05 14:01:20 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/push_swap.h"
#include "../inc/my-libft/inc/libft.h"

int	swap_nodes(t_stack **stack)
{
	t_elem	*prev;
	int		temp_val;

	prev = ((*stack)->head)->prev;
	if (!prev || (prev == (*stack)->tail) || prev->prev == (*stack)->tail)
		return (0);
	temp_val = prev->prev->val;
	prev->prev->val = prev->val;
	prev->val = temp_val;
	return (1);
}

int	swap_a(t_stack **stack_a)
{
	if (!swap_nodes(stack_a))
		return (0);
	return (ft_printf("sa\n") == 3);
}

int	swap_b(t_stack **stack_b)
{
	if (!swap_nodes(stack_b))
		return (0);
	return (ft_printf("sb\n") == 3);
}

int	swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	if (!swap_nodes(stack_a))
		return (0);
	if (!swap_nodes(stack_b))
		return (0);
	return (ft_printf("ss\n") == 3);
}

