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
