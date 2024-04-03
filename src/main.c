#include "../inc/headers/push_swap.h"
#include "../inc/my-libft/inc/libft.h"

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
			return (ft_printf("\nFaulty argv = %s", argv[i]), 0);
		insert_node(stack_a, val);
		while (k < argc)
		{
			if (ft_atoi(argv[k]) == 0 && argv[k][0] != '0')
				return (0);
			if (val == ft_atoi(argv[k]))
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

int	free_stacks(t_stack **a, t_stack **b, char ***split, int no_cap)
{
	if (!no_cap)
	{
		free_stack(a);
		free_stack(b);
	}

	int	i = 0;

	if (!*split)
		return (0);
	while ((*split)[i])
	{
		free((*split)[i]);
		(*split)[i] = NULL;
		i++;
	}
	free(*split);
	*split = NULL;
	return (no_cap);
}

int	check_dup(char **arg)
{
	int	i;
	int	k;

	i = 0;
	while (arg[i])
	{
		k = i + 1;
		while (arg[k])
		{
			if (ft_atoi(arg[i]) == ft_atoi(arg[k]))
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}


int	convert_split(int argc, char **argv, t_stack **a, t_stack **b)
{
	char	**split;
	int	val;
	int	i;
	
	split = NULL;
	if (argc == 2)
	{
		if (argv[1][0])
		{
			if (!argv[1][1])
				return (free_stacks(a, b, &split, 0));
		}
		i = 0;
		split = ft_split(argv[1], ' ');
		if (!check_dup(split))
			return (free_stacks(a, b, &split, 0));
		while (split[i])
		{
			val = ft_atoi(split[i]);
			if (!val && split[i][0] != '0')
				return (free_stacks(a, b, &split, 0));
			insert_node(a, val); 
			i++;
		}
	}
	return (free_stacks(a, b, &split, 1));
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		t_stack	*stack_a;
		t_stack	*stack_b;


		if (argc >= 2 && (!argv[1][0] || !argv[2][0]))
			return (ft_printf("Error\n"), 0);

		stack_a = init_stack();
		stack_b = init_stack();

		if (argc == 2)
		{
			if (!convert_split(argc, argv, &stack_a, &stack_b))
				return (ft_printf("Error\n"), 0);
		}
		else if (!check_duplicates(&stack_a, argc, argv))
			return (ft_printf("Error\n"), 0);
		push_swap(&stack_a, &stack_b);
		
		print_stacks(stack_a, stack_b);
		free_stack(&stack_b);
		free_stack(&stack_a);
		return (0);
	}
	return (0);
}
