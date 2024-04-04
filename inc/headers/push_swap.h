#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../my-libft/inc/libft.h"

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
	int	size;
	int	median;
}				t_stack;

int     check_input(char *s);
int     free_stacks(t_stack **a, t_stack **b, char ***split, int no_cap);
int     check_dup(char **arg);
int     check_duplicates(t_stack **stack_a, int argc, char **argv);
int     convert_split(int argc, char **argv, t_stack **a, t_stack **b);

// operations
int     insert_node(t_stack **stack, int value);
t_stack *init_stack(void);
t_elem  *pop_node(t_stack **stack);
void    swap_nodes(t_stack **stack);
int     swap_a(t_stack **stack_a);
int     swap_b(t_stack **stack_b);
int     swap_ss(t_stack **stack_a, t_stack **stack_b);
int     push_a(t_stack **stack_a, t_stack **stack_b);
int     push_b(t_stack **stack_a, t_stack **stack_b);
int     rotate_up(t_stack **stack, int s);
int     rotate_down(t_stack **stack, int s);
int     rr(t_stack **stack_a, t_stack **stack_b);
int     rrr(t_stack **stack_a, t_stack **stack_b);

// solving
t_elem	*get_biggest_node(t_stack *s);
t_elem	*get_smallest_node(t_stack *s);
t_elem	*get_closest_node(t_elem *node, t_stack *s);
t_elem	*find_ideal_position(t_elem *node, t_stack *b);
int	get_node_index(t_elem *target, t_stack *s);
int	get_different_count_median(t_stack *a, t_stack *b, int ia, int ib);
int	get_operation_count(t_stack *a, t_stack *b, int ia, int ib);
int	get_number_operations(t_elem *node, t_stack *a, t_stack *b);
t_elem	*find_cheapest_node(t_stack *a, t_stack *b);
void	push_swap(t_stack **a, t_stack **b);

// temporary util
int	ft_atoi(const char *nptr);
void	print_stacks(t_stack *a, t_stack *b);
void	update_median(t_stack **s);

#endif
