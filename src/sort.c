#include "../inc/headers/push_swap.h"
#include "../inc/my-libft/inc/libft.h"

t_elem	*get_biggest_node(t_stack *s)
{
	t_elem	*cur;
	t_elem	*max;

	cur = s->head->prev;
	if (!cur || cur == s->tail)
		return (NULL);
	max = s->head->prev;
	while (cur != s->tail)
	{
		if (cur->val > max->val)
			max = cur;
		cur = cur->prev;
	}
	return (max);
}

t_elem	*get_smallest_node(t_stack *s)
{
	t_elem	*cur;
	t_elem	*min;

	cur = s->head->prev;
	if (!cur || cur == s->tail)
		return (NULL);
	min = s->head->prev;
	while (cur != s->tail)
	{
		if (cur->val < min->val)
			min = cur;
		cur = cur->prev;
	}
	return (min);
}

t_elem	*get_closest_node(t_elem *node, t_stack *s)
{
	int	diff;
	int	diff_min;
	t_elem	*closest;
	t_elem	*cur;

	cur = s->head->prev;
	if (!cur || cur == s->tail)
		return (NULL);
	closest = cur;
	diff_min = 0;
	while (cur != s->tail)
	{
		diff = node->val - cur->val;
		if (diff > 0)
		{
			if (!diff_min || (diff_min && diff < diff_min))
			{
				closest = cur;
				diff_min = diff;
			}
		}
		else if (diff < 0 && !diff_min)
			if (diff > node->val - closest->val)
				closest = cur;
		cur = cur->prev;
	}
	return (closest);
}

t_elem	*get_closest_node_big(t_elem *node, t_stack *s)
{
	int	diff;
	int	diff_min;
	t_elem	*closest;
	t_elem	*cur;

	cur = s->head->prev;
	if (!cur || cur == s->tail)
		return (NULL);
	closest = cur;
	diff_min = 0;
	while (cur != s->tail)
	{
		diff = cur->val - node->val;
		if (diff > 0)
		{
			if (!diff_min || (diff_min && diff < diff_min))
			{
				closest = cur;
				diff_min = closest->val - node->val;
			}
		}
		else if (diff < 0 && !diff_min)
			if (diff > closest->val - node->val)
				closest = cur;
		cur = cur->prev;
	}
	return (closest);
}

t_elem	*find_ideal_position(t_elem *node, t_stack *b)
{
	// returns the node that is to be shifted to the top of stack b
	t_elem	*biggest;
	t_elem	*smallest;
	t_elem	*closest;

	biggest = get_biggest_node(b);
	smallest = get_smallest_node(b);

	if (node->val > biggest->val || node->val < smallest->val)
		return (biggest);
	closest = get_closest_node(node, b);
	return (closest);
}

int	get_node_index(t_elem *target, t_stack *s)
{
	t_elem	*cur;
	int	i;

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

int	get_different_count_median(t_stack *a, t_stack *b, int ia, int ib)
{
	int	i;
	int	y;

	if (ia < a->median)
		i = ia;
	else if (ia >= a->median)
		i = a->size - ia;
	if (ib < b->median)
		y = ib;
	else if (ib >= b->median)
		y = b->size - ib;
	return (i + y);
}

int	get_operation_count(t_stack *a, t_stack *b, int ia, int ib)
{
	if (ia < a->median && ib < b->median)
	{
		if (ia > ib)
			return (ia);
		return (ib);
	}
	else if (ia >= a->median && ib >= b->median)
	{
		if (a->size - ia > b->size - ib)
			return (a->size - ia);
		return (b->size - ib);
	}	
	return (get_different_count_median(a, b, ia, ib));
}

int	get_number_operations(t_elem *node, t_stack *a, t_stack *b)
{
	int	count;
	int	ia;
	int	ib;
	t_elem	*inode;

	inode = find_ideal_position(node, b); 
	ia = get_node_index(node, a);
	ib = get_node_index(inode, b);

	count = get_operation_count(a, b, ia, ib);
	return (count);
}

t_elem	*find_cheapest_node(t_stack *a, t_stack *b)
{
	t_elem	*cur;
	t_elem	*cheapest;
	int	count;
	int	c;

	// loops through stack_a or until n != 1 to get the cheapest node and returns it
	cur = a->head->prev;
	cheapest = cur;
	count = get_number_operations(cheapest, a, b);
	while (cur && cur != a->tail)
	{
		c = get_number_operations(cur, a, b);
		if (c < count)
		{
			count = c;
			cheapest = cur;
		}
		cur = cur->prev;
	}
	return (cheapest);
}

int	check_difference(int ia, int ib, t_stack *a, t_stack *b)
{
	if (ia < a->median)
	{
		if (ib < b->median)
			return (1);
		else if (ib >= b->median)
			return (ib - ia < b->median);
	}
	else if (ia >= a->median)
	{
		if (ib >= b->median)
			return (2);
		else if (ib < b->median)
			return ((ib + (a->size - ia) >= b->median) + 1);
	}
	return (0);
}

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
		if (check_difference(ia, ib, a, b) == 1 && (a->head->prev->val != va && b->head->prev->val != vb))
			rr(&a, &b);
		else if (check_difference(ia, ib, a, b) == 2 && (a->head->prev->val != va && b->head->prev->val != vb))
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
		print_stacks(a, b);
		ft_printf("A->head->prev = %d, VA = %d\n", a->head->prev->val, va);
		ft_printf("B->head->prev = %d, VB = %d\n", b->head->prev->val, vb);
		ft_printf("A->head->prev == VA = %d\n", a->head->prev->val == va);
		ft_printf("B->head->prev == VB = %d\n", b->head->prev->val == vb);
		printf("INFINTE LOOPED\n");
	}
}

void	sort_three(t_stack *s)
{
	if (s->size > 2)
	{
		if ((s->head->prev->prev)->val > (s->tail->next)->val && (s->head->prev->prev)->val > (s->head->prev)->val)
			rotate_down(&s, 1);
		else if ((s->head->prev)->val > (s->head->prev->prev)->val && (s->head->prev)->val > (s->tail->next)->val)
			rotate_up(&s, 1);
	}
	if ((s->head->prev)->val > (s->head->prev->prev)->val)
		swap_a(&s);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_elem	*cheapest;
	t_elem	*ideal;

	if ((*a)->size <= 3)
	{
		sort_three(*a);
		print_stacks(*a, *b);
		return ;
	}
	push_a(a, b);
	push_a(a, b);

	while ((*a)->size > 3)
	{
		cheapest = find_cheapest_node(*a, *b);
		ideal = find_ideal_position(cheapest, *b);
		print_stacks(*a, *b);
		put_to_top(cheapest, ideal, *a, *b);
		push_a(a, b);
	}
	// sort a
	sort_three(*a);
	while ((*b)->head->prev != (*b)->tail)
	{
		cheapest = (*b)->head->prev;
		ideal = get_closest_node_big(cheapest, *a);
		if (get_biggest_node(*a)->val < cheapest->val)
		{
			push_b(a, b);
			rotate_up(a, 1);
		}
		else
		{
			put_to_top(ideal, cheapest, *a, *b);
			push_b(a, b);
		}
		print_stacks(*a, *b);
	}
	t_elem	*min;
	int	is_half;
	int	val;

	min = get_smallest_node(*a);
	is_half = get_node_index(min, *a) < (*a)->median;
	val = min->val;
	while ((*a)->head->prev->val != val)
	{
		if (is_half)
			rotate_up(a, 1);
		else
			rotate_down(a, 1);
		print_stacks(*a, *b);
	}
	print_stacks(*a, *b);
}
