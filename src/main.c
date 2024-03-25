#include "../inc/headers/push_swap.h"

void	print_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (!argv)
		return ;
	while (i < argc)
	{
		if (i != argc - 1)
			printf("%s ", argv[i]);
		else
			printf("%s\n", argv[i]);
		i++;
	}
}

int	check_duplicates(t_stack **stack_a, int argc, char **argv)
{
	int	i;
	int	k;
	int	val;

	i = 1;
	while (i < argc)
	{
		k = i + 1;
		val = ft_atoi(argv[i]);
		if (val == 0 && argv[i][0] != '0')
			return (0);
		insert_node(stack_a, val);
		while (k < argc)
		{
			if (ft_atoi(argv[k]) == 0 && argv[k][0] != 0)
				return (0);
			if (val == ft_atoi(argv[k]))
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		t_stack	*stack_a;
		t_stack	*stack_b;

		stack_a = init_stack();
		stack_b = init_stack();

		if (!check_duplicates(&stack_a, argc, argv))
		{
			free_stack(&stack_a);
			free_stack(&stack_b);
			return (printf("Error\n"), 0);
		}
		printf("Init a and b:\n");
		print_stacks(stack_a, stack_b);
		swap_a(&stack_a);
		print_stacks(stack_a, stack_b);
		push_a(&stack_a, &stack_b);
		print_stacks(stack_a, stack_b);
		push_a(&stack_a, &stack_b);
		print_stacks(stack_a, stack_b);
		push_a(&stack_a, &stack_b);
		print_stacks(stack_a, stack_b);
		rr(&stack_a, &stack_b);
		print_stacks(stack_a, stack_b);
		rrr(&stack_a, &stack_b);
		print_stacks(stack_a, stack_b);
		swap_a(&stack_a);
		print_stacks(stack_a, stack_b);
		push_b(&stack_a, &stack_b);
		print_stacks(stack_a, stack_b);
		push_b(&stack_a, &stack_b);
		print_stacks(stack_a, stack_b);
		push_b(&stack_a, &stack_b);
		print_stacks(stack_a, stack_b);
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (0);
	}
	return (print_args(argc, argv), 0);
}
