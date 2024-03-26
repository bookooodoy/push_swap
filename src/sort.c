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
