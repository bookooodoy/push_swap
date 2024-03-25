#include "../inc/headers/push_swap.h"

static int	push_rand_values(t_stack **a, t_stack **b)
{
	static int	max_num;

	push_a(a, b);
	push_a(a, b);

	if (((*b)->head)->prev)->val > ((((*b)->head->prev)->prev)->val)
		return (max_num = (*b)->head->prev->val, max_num);
	else
		return (max_num = ((*b)->head->prev)->prev->val, max_num);
}

int	compare_size(t_elem *node, int biggest, t_stack **b)
{
	int	value;
	int	smallest;
	t_elem	*cur;

	value = node->val;
	if (value > *biggest)
		return (1);
	cur = (*b)->head->prev;
	while (cur != (*b)->tail)
	{
		smallest = value;
		if (value < smallest)
			return (-1);
		cur = cur->prev;
	}
	return (0);
}

int	get_median_value(int target, t_stack *s)
{
	t_elem	*cur;
	int	i;

	i = 0;
	cur = s->head->prev;
	while (cur != s->tail && cur->val != target)
	{
		i++;
		cur = cur->prev;
	}
	return ((s->size / 2) > i);
}

int	get_num_operations(t_elem *elem, t_stack **a, t_stack **b, int *biggest)
{
	// check if the number is the new biggest or smallest
	int	new_biggest;

	if (compare_size(elem, biggest, b) == 1)
	{
		// 1 equals biggest
		// so the old biggest should be at the top
		// get the median value of the biggest
		// get the median value of the target
	}
	return (0);
}

t_elem	*find_cheapest_number(t_stack **a, t_stack **b, int *biggest)
{
	// finds the cheapest number and pops it from the list
	t_elem	*cur;
	int	min;

	cur = ((*a)->head)->prev;
	min = get_num_operations(cur, a, b, biggest);
	while (cur != ((*a)->tail))
	{
		if (min == 1)
			return (NULL);//TODO: pop the min
		cur = cur->prev;
		if (get_num_operations(cur, a, b, biggest) < min)
			min = get_num_operations(cur, a, b);
	}
	return (NULL);//TODO:pop
}

void	solve(t_stack **a, t_stack **b)
{
	t_elem	*cheapest;
	t_elem	*cur;
	int	max;

	max = push_rand_values(a, b);
	cheapest = find_cheapest_number(a, b, &max);
	while ((*a)->size != 3 && !(*b)->size)
	{
		// move the cheapest node to the top
		// push it to b
	}
	// sort the stack_b 
	// push everything back to a
	// sort a
}
