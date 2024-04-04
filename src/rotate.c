/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:50:55 by nraymond          #+#    #+#             */
/*   Updated: 2024/04/04 14:52:10 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/push_swap.h"
#include "../inc/my-libft/inc/libft.h"


int	rotate_up(t_stack **stack, int s)
{
	t_elem	*cur;
	int		temp_val;

	cur = ((*stack)->head)->prev;
	while (cur->prev && cur->prev != (*stack)->tail)
	{
		temp_val = cur->val;
		cur->val = cur->prev->val;
		cur->prev->val = temp_val;
		cur = cur->prev;
	}
	if (s == 1)
		return (ft_printf("ra\n") != -1);
	else if (!s)
		return (ft_printf("rb\n") != -1);
}

int	rotate_down(t_stack **stack, int s)
{
	t_elem	*cur;
	int		temp_val;

	cur = ((*stack)->tail)->next;
	while (cur->next && cur->next != (*stack)->head)
	{
		temp_val = cur->val;
		cur->val = cur->next->val;
		cur->next->val = temp_val;
		cur = cur->next;
	}
	if (s == 1)
		return (ft_printf("rra\n") != -1);
	else if (!s)
		return (ft_printf("rrb\n") != -1);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_up(stack_a, -1);
	rotate_up(stack_b, -1);
	return (ft_printf("rr\n") != -1);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_down(stack_a, -1);
	rotate_down(stack_b, -1);
	return (ft_printf("rrr\n") != -1);
}
