#include "../inc/headers/push_swap.h"

void	insert_node(t_stack **stack, int value)
{
	t_elem	*new_node;
	t_elem	*prev;

	new_node = malloc(sizeof(t_elem));
	if (!new_node)
		return ; // TODO: protect malloc
	prev = ((*stack)->head)->prev;
	((*stack)->head)->prev->next = new_node;
	new_node->val = value;
	new_node->next = (*stack)->head;
	new_node->prev = prev;

	((*stack)->head)->prev = new_node;
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
}

t_elem	*pop_node(t_stack **stack)
{
	t_elem	*prev;

	prev = ((*stack)->head)->prev;
	if (prev == (*stack)->tail)
		return (NULL);
	(prev->prev)->next = (*stack)->head;
	((*stack)->head)->prev = prev->prev;
	return (prev);
}

void	swap_nodes(t_stack **stack)
{
	t_elem	*prev;
	int	temp_val;

	prev = ((*stack)->head)->prev;
	if ((prev == (*stack)->tail) || prev->prev == (*stack)->tail)
		return ;
	temp_val = prev->prev->val;
	prev->prev->val = prev->val;
	prev->val = temp_val;
}

void	swap_a(t_stack **stack_a)
{
	swap_nodes(stack_a);
	printf("sa\n");
}

void	swap_b(t_stack **stack_b)
{
	swap_nodes(stack_b);
	printf("sb\n");
}

void	swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_nodes(stack_a);
	swap_nodes(stack_b);
	printf("ss\n");
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_elem	*pop;

	pop = pop_node(stack_a);
	if (!pop)
		return ;
	insert_node(stack_b, pop->val);
	free(pop);
	printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_elem	*pop;

	pop = pop_node(stack_b);
	if (!pop)
		return ;
	insert_node(stack_a, pop->val);
	free(pop);
	printf("pb\n");
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
		printf("ra\n");
	else if (!s)
		printf("rb\n");
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
		printf("rra\n");
	else if (!s)
		printf("rrb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_up(stack_a, -1);
	rotate_up(stack_b, -1);
	printf("rr\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_down(stack_a, -1);
	rotate_down(stack_b, -1);
	printf("rrr\n");
}
void	print_stacks(t_stack *a, t_stack *b)
{
	t_elem	*c_a = a->head->prev;
	t_elem	*c_b = b->head->prev;

	printf("\n");
	while ((c_a != a->tail) || (c_b != b->tail))
	{
		if (c_a != a->tail)
		{
			printf("%3d", c_a->val);
			c_a = c_a->prev;
		}
		if (c_b != b->tail)
		{
			printf("%3d", c_b->val);
			c_b = c_b->prev;
		}
		printf("\n");
		
	}
	printf("  _  _\n");
	printf("  a  b\n\n");
}
