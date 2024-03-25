#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

//STRUCTS
typedef struct s_elem
{
	struct s_elem *next;
	struct s_elem *prev;
	int		val;
}				t_elem;

typedef struct s_stack
{
	t_elem *head;
	t_elem *tail;
}				t_stack;

//main
void	print_args(int argc, char **argv);
int	check_duplicates(t_stack **stack_a, int argc, char **argv);

// operations
t_stack	*init_stack(void);
void	insert_node(t_stack **stack, int value);
void	free_stack(t_stack **stack);
t_elem	*pop_node(t_stack **stack);
void	swap_nodes(t_stack **stack);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_ss(t_stack **stack_a, t_stack **stack_b);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	rotate_up(t_stack **stack, int s);
void	rotate_down(t_stack **stack, int s);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

// temporary util
int	ft_atoi(const char *nptr);
void	print_stacks(t_stack *a, t_stack *b);

#endif
