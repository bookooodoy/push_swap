#include "../inc/headers/push_swap.h"

int	is_smallest(int number, t_stack *s)
{
	t_elem	*cur;
	int	min;

	cur = s->head->prev;
	min = cur->val;
	while (cur != s->tail)
	{
		cur = cur->prev;
		if (cur->val < min)
			min = cur->val;
	}
	return (number < min);
}

int	is_biggest(int number, t_stack *s)
{
	t_elem	*cur;
	int	max;

	cur = s->head->prev;
	max = cur->val;
	while (cur != s->tail)
	{
		cur = cur->prev;
		if (cur->val > max)
			max = cur->val;
	}
	return (number > max);
}

int	get_node_index(t_elem *node, t_stack *s)
{
	t_elem	*cur;
	int	i = 0;

	cur = s->head->prev;
	while (cur != s->tail && cur != node)
	{
		cur = cur->prev;
		i++;
	}
	return (i);
}

int	check_median(t_stack *a, t_stack *b, int ia, int ib)
{
	int	median_a;
	int	median_b;

	median_a = a->size / 2;
	median_b = b->size / 2;

	return (ia > median_a && ib > median_b || ia < median_a && ib < median_b);
}

int	get_mdis(t_stack *a, t_stack *b, int ia, int ib)
{
	int	median_a;
	int	median_b;

	// get the smallest stack and the median position of the index
	// increase if higher decrease if lower
	median_a = a->size / 2;
        median_b = b->size / 2;

	if (a->size >= b->size)
	{
		if (ia >= median_a)
			return (ib + (size_a - ia) > median_b);
		return (ib - ia <= median_b);
	}
	else
	{
		if (ib >= median_b)
			return (ia + (size_b - ib) > median_a);
		return (ia - ib <= median_a);
	}
}


int	get_number_operations(t_elem *elem, t_stack *a, t_stack *b, t_elem *biggest_b)
{
	int	smallest_to_top;
	int	ia;
	int	ib;
	int	num_operations = 0;
	t_elem	*cur;

	ia = get_node_index(elem, a);
	ib = get_node_index(biggest_b, b);
	if (is_biggest(elem->val) || is_smallest(elem->val))
	{
		// shift largest in b on top

		if (check_median(a, b, ia, ib))
		{
			if (a->size <= b->size)
			{
				if (b->size <= median_b)
					num_operations = ib;
				else
					num_operations = b->size - ib;
			}
			else if (a->size > b->size)
			{
				if (a->size <= median_a)
					num_operations = ia;
				else
					num_operations = (a->size - ia);
			}
		}
		else
		{
			// check if advancing for the smallest distance between index & end changes median in other stack
			if (
			// if it changes it, num_operations = size_smallest - node_index_smallest + (size_largest - node_bigger_index - num_operations;
			
		}
	}
}

int	find_cheapest_number(t_stack *a, t_stack *b)
{
	t_elem	*cur;
	int	cheapest;
	int	cheapest_op;

	cur = (a)->head->prev;
	cheapest_op = get_number_operations(cur, a, b);
	cheapest = cur->val;
	while (cur != (a)->tail)
	{
		cur = cur->prev;
		if (get_number_operations(cur, a, b) < cheapest_op)
		{
			cheapest_op = get_number_operations(cur, a, b);
			cheapest = cur->val;
		}
	}
	return (cheapest);
}


void	push_swap(t_stack **a, t_stack **b)
{
	// push 2
	// push and sort b while a != 3
	// sort a == 3
	// push back everything
	// sort special cases
}
