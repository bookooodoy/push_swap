/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:17:46 by nraymond          #+#    #+#             */
/*   Updated: 2024/01/31 13:23:04 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my-libft/inc/libft.h"

t_dbl	*get_ldlist(int **tab)
{
	t_dlist	*head;
	t_dlist	*tail;
	int	i;

	i = 0;
	head = malloc(sizeof(t_dlist));
	if (!head)
		return (NULL);
	head->prev = NULL;
	tail = malloc(sizeof(t_dlist));
	if (!tail)
		return (free(head), NULL);
	head->next = tail;
	tail->next = NULL;
	tail->prev = head;
	while (*tab[i])
	{
		if (!lst_add_last(&tail, val))
		{
			free(*tab);
			return (*tab = NULL, NULL);
		}
		i++;
	}
	t_dbl = malloc(sizeof(t_dbl));
	if (!t_dbl)
		return (NULL) // TODO: free everything
	t_dbl->head = head;
	t_dbl->tail = tail;
	return (t_dbl);
}

int	lst_add_last(t_dlist **tail, int val)
{
	// add from the tail
	t_dlist	*last;
	t_dlist	*new;

	new = malloc(sizeof(t_dlist));
	if (!new)
		return (0);
	new->val = val;
	last = (*tail)->prev;
	last->next = new;
	new->prev = last;
	new->next = (*tail);
	(*tail)->prev = new;
	return (1);
}

int	lst_add_first(t_dlist **head, int val)
{
	t_dlist	*first;
	t_dlist	*new;

	new = malloc(sizeof(t_dlist));
	if (!new)
		return (0);
	new->val = val;
	first = (*head)->next;
	new->next = first;
	new->prev = (*head);
	(*head)->next = new;
	return (1);
}

void	swap_a_b(t_dbl **list)
{
	// check if the next of head is tail
	t_dlist	*a;
	t_dlist	*b;
	t_dlist	*prev;
	t_dlist	*next;

	if (((*list)->head)->next == ((*list)->tail))
		return ;
	// swap the previous and next of a and b
	// get the first and second node in a and b
	a = ((*list)->head)->next;
	b = a->next;
	if (a || b)
		return ;
	next = b->next;
	prev = ((*list)->head);
	b->prev = prev;
	a->next = next;
	// change the addreses of the following nodes
	next->prev = a;
	prev->next = b;

}

void	swap_ss(t_dbl **list1, t_dbl **list2)
{
	swap_a_b(list1);
	swap_a_b(list2);
}


void	push_a(t_dbl **list1, t_dbl **list2)
{
	t_dlist	*next;
	t_dlist	*swap;

	if (!((*list2)->head) || !(((*list2)->head)->next))
		return ;
	// add last and change the value of the first one
	// swap element
	lst_add_first(&((*list1)->head), (((*list2)->head)->next)->val);
	// free the node in list2
	next = (((*list2)->head)->next)->next;
	next->prev = ((*list2)->head);
	((*list2)->head)->next = prev;
	free(((*list2)->head)->next);
	next->prev = ((*list2)->head);
}
