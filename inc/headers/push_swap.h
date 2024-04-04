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

// sort
void	put_to_top(t_elem *target_a, t_elem *target_b, t_stack *a, t_stack *b);
void	sort_three(t_stack *s);
void	sort_first_a(t_stack **a, t_stack **b);
void	sort_second_b(t_stack **a, t_stack **b);
void	sort_last_a(t_stack **a);
void	solve(t_stack **a, t_stack **b);

// count
int	get_operation_count(t_stack *a, t_stack *b, int ia, int ib);
int	get_number_operations(t_elem *node, t_stack *a, t_stack *b);
t_elem	*find_cheapest_node(t_stack *a, t_stack *b);

// median
int	get_different_count_median(t_stack *a, t_stack *b, int ia, int ib);
int	check_difference(int ia, int ib, t_stack *a, t_stack *b);

// search big
t_elem	*get_biggest_node(t_stack *s);
void	set_closest_big(t_elem **closest, t_elem *cur, t_elem *node, int *diff_min);
t_elem	*get_closest_node_big(t_elem *node, t_stack *s);
t_elem	*find_ideal_position(t_elem *node, t_stack *b);

// search small
t_elem	*get_smallest_node(t_stack *s);
void	set_closest(t_elem **closest, t_elem *cur, t_elem *node, int *diff_min);
t_elem	*get_closest_node(t_elem *node, t_stack *s);

// parse
int	check_input(char *s);
int	free_stacks(t_stack **a, t_stack **b, char ***split, int no_cap);
int	check_dup(char **arg);
int	check_duplicates(t_stack **stack_a, int argc, char **argv);
int	convert_split(int argc, char **argv, t_stack **a, t_stack **b);

// push
int	push_a(t_stack **stack_a, t_stack **stack_b);
int	push_b(t_stack **stack_a, t_stack **stack_b);
t_elem	*pop_node(t_stack **stack);

// rotate
int	rotate_up(t_stack **stack, int s);
int	rotate_down(t_stack **stack, int s);
int	rr(t_stack **stack_a, t_stack **stack_b);
int	rrr(t_stack **stack_a, t_stack **stack_b);

// stack
int	insert_node(t_stack **stack, int value);
t_stack	*init_stack(void);
int	stack_sorted(t_stack *s);

//swap
void	swap_nodes(t_stack **stack);
int	swap_a(t_stack **stack_a);
int	swap_b(t_stack **stack_b);
int	swap_ss(t_stack **stack_a, t_stack **stack_b);

//utils
void	free_stack(t_stack **stack);
void	update_median(t_stack **s);
int	get_node_index(t_elem *target, t_stack *s);

#endif
