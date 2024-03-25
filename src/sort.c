#include "../inc/headers/push_swap.h"

static int	push_rand_values(t_stack **a, t_stack **b)
{
	static int	max_num;

	push_a(a, b);
	push_a(a, b);

	if ((*b)->head)->prev > (((*b)->head->prev)->prev)
		return (max_num = (*b)->head->prev, max_num);
	else
		return (max_num = ((*b)->head->prev)->prev, max_num);
}

int	get_num_operations(t_elem *elem, t_stack **a, t_stack **b)
{
	// if the number we push is the smallest or biggest, it should be above the old biggest number;
	// if the old biggest is not at the top
	// shift up or down (relative position based off median) (if not at the top in a and pos not at the top in b rr both)
	// until the old biggest is at the top
	// count until
	// return num operations
	// if the number is not biggest or largest
	// find its relative biggest or smallest and push just above

	return (0);
}

t_elem	*find_cheapest_number(t_stack **a, t_stack **b)
{
	// finds the cheapest number and pops it from the list
	t_elem	*cur;
	int	min;

	cur = ((*a)->head)->prev;
	min = get_num_operations(cur, a, b);
	while (cur != ((*a)->tail))
	{
		if (min == 1)
			return (NULL);//TODO: pop the min
		cur = cur->prev;
		if (get_num_operations(cur, a, b) < min)
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
	cheapest = find_cheapest_number(a, b);
	while ((*a)->size != 3 && !(*b)->size)
	{
		// move the cheapest node to the top
		// push it to b
	}
	// sort the stack_b 
	// push everything back to a
	// sort a
}
