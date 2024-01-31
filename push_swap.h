/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:53:17 by nraymond          #+#    #+#             */
/*   Updated: 2024/01/31 12:18:23 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my-libft/inc/libft.h"

typedef struct l_dlist
{
	int	val;
	struct l_dlist	*next;
	struct l_dlist	*prev;
}	t_dlist;

typedef struct DoublyLinkedList
{
	t_dlist* head;
	t_dlist* tail;
}	t_dbl;


t_dbl	*get_ldlist(int **tab);
int	lst_add_last(t_dlist **tail, int val);
void	swap_a(t_dbl **list);
