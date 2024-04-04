/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:52:21 by nraymond          #+#    #+#             */
/*   Updated: 2024/04/04 16:52:23 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/push_swap.h"
#include "../inc/my-libft/inc/libft.h"

void	free_stack(t_stack **stack)
{
	t_elem	*cur;
	t_elem	*next;

	if (!*stack)
		return ;
	cur = (*stack)->tail;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(*stack);
}

void	update_median(t_stack **s)
{
	if (!*s)
		return ;
	(*s)->median = (*s)->size / 2;
}

int	get_node_index(t_elem *target, t_stack *s)
{
	t_elem	*cur;
	int		i;

	i = 0;
	if (!target || !s)
		return (-1);
	cur = s->head->prev;
	while (cur != s->tail)
	{
		if (cur == target)
			return (i);
		cur = cur->prev;
		i++;
	}
	return (-1);
}
