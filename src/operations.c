#include "../inc/headers/push_swap.h"
#include "../inc/my-libft/inc/libft.h"

void	insert_node(t_stack **stack, int value)
{
	t_elem	*new_node;
	t_elem	*prev;

	new_node = malloc(sizeof(t_elem));
	if (!new_node)
		return ; // TODO: protect malloc
	prev = (*stack)->head->prev;
	new_node->val = value;
	new_node->next = (*stack)->head;
	new_node->prev = prev;
	
	prev->next = new_node;
	((*stack)->head)->prev = new_node;
	(*stack)->size += 1;
	update_median(stack);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	t_elem	*head;
	t_elem	*tail;

	head = malloc(sizeof(t_elem));
	tail = malloc(sizeof(t_elem));
	if (!tail || !head)
	{
		free(head);
		return (free(tail), NULL);
	}
	head->prev = tail;
	head->next = NULL;
	tail->prev = NULL;
	tail->next = head;
	stack->head = head;
	stack->tail = tail;
	stack->size = 0;
	return (stack);
}

t_elem	*pop_node(t_stack **stack)
{
	t_elem	*pop;

	pop = ((*stack)->head)->prev;
	if (!pop || pop == (*stack)->tail)
		return (NULL);
	return (pop);
}

void	swap_nodes(t_stack **stack)
{
	t_elem	*prev;
	int	temp_val;

	prev = ((*stack)->head)->prev;
	if (!prev || (prev == (*stack)->tail) || prev->prev == (*stack)->tail)
		return ;
	temp_val = prev->prev->val;
	prev->prev->val = prev->val;
	prev->val = temp_val;
}

void	swap_a(t_stack **stack_a)
{
	swap_nodes(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_stack **stack_b)
{
	swap_nodes(stack_b);
	ft_printf("sb\n");
}

void	swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_nodes(stack_a);
	swap_nodes(stack_b);
	ft_printf("ss\n");
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_elem	*pop;
	t_elem	*prev;

	pop = pop_node(stack_b);
	if (!pop)
		return ;
	prev = (*stack_b)->head->prev->prev;
	(*stack_b)->head->prev = prev;
	prev->next = (*stack_b)->head;
	insert_node(stack_a, pop->val);
	free(pop);
	(*stack_b)->size -= 1;
	update_median(stack_b);
	ft_printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_elem	*pop;
	t_elem	*prev;

	pop = pop_node(stack_a);
	if (!pop)
		return ;
	prev = (*stack_a)->head->prev->prev;
	(*stack_a)->head->prev = prev;
	prev->next = (*stack_a)->head;
	insert_node(stack_b, pop->val);
	free(pop);
	(*stack_a)->size -= 1;
	update_median(stack_b);
	ft_printf("pb\n");
}

void	rotate_up(t_stack **stack, int s)
{
	t_elem	*cur;
	int	temp_val;

	cur = ((*stack)->head)->prev;
	while (cur->prev && cur->prev != (*stack)->tail)
	{
		temp_val = cur->val;
		cur->val = cur->prev->val;
		cur->prev->val = temp_val;
		cur = cur->prev;
	}
	if (s == 1)
		ft_printf("ra\n");
	else if (!s)
		ft_printf("rb\n");
}

void	rotate_down(t_stack **stack, int s)
{
	t_elem	*cur;
	int	temp_val;

	cur = ((*stack)->tail)->next;
	while (cur->next && cur->next != (*stack)->head)
	{
		temp_val = cur->val;
		cur->val = cur->next->val;
		cur->next->val = temp_val;
		cur = cur->next;
	}
	if (s == 1)
		ft_printf("rra\n");
	else if (!s)
		ft_printf("rrb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_up(stack_a, -1);
	rotate_up(stack_b, -1);
	ft_printf("rr\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_down(stack_a, -1);
	rotate_down(stack_b, -1);
	ft_printf("rrr\n");
}
void	print_stacks(t_stack *a, t_stack *b)
{
	t_elem	*c_a = a->head->prev;
	t_elem	*c_b = b->head->prev;

	ft_printf("\n");
	while ((c_a != NULL && c_a != a->tail) || (c_b != NULL && c_b != b->tail))
	{
		if (c_a != a->tail)
		{
			ft_printf("%3d", c_a->val);
			c_a = c_a->prev;
		}
		else
			ft_printf("  .");
		if (c_b != b->tail)
		{
			ft_printf("%3d", c_b->val);
			c_b = c_b->prev;
		}
		else
			ft_printf("  .");
		ft_printf("\n");
		
	}
	ft_printf("  _  _\n");
	ft_printf("  a  b\n\n");
}
