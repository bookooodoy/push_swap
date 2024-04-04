/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:24:19 by nraymond          #+#    #+#             */
/*   Updated: 2024/04/04 13:29:05 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/push_swap.h"
#include "../inc/my-libft/inc/libft.h"

int	check_input(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (i != 0 && !ft_isdigit(s[i]))
			return (0);
		else if (i == 0 && !ft_isdigit(s[i]) && s[i] != '+' && s[i] != '-')
			return (0);
		i++;
	}
	return (1);
}


int	free_stacks(t_stack **a, t_stack **b, char ***split, int no_cap)
{
	int	i;

	i = 0;
	if (!no_cap)
	{
		free_stack(a);
		free_stack(b);
	}
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
	if (!arg)
		return (0);
	while (arg[i])
	{
		if (!check_input(arg[i]))
			return (0);
		k = i + 1;
		while (arg[k])
		{
			if (ft_atoi(arg[i]) == ft_atoi(arg[k]))
				return (0);
			k++;
		}
		i++;
	}
	return (i);
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
			if (!argv[1][1])
				return (free_stacks(a, b, &split, 0));
		split = ft_split(argv[1], ' ');
		i = check_dup(split);
		if (!i)
			return (free_stacks(a, b, &split, 0));
		while (i)
		{
			if (!check_input(split[--i]) || (ft_atoi(split[i]) && split[i][0] != '0'))
				return (free_stacks(a, b, &split, 0));
			if (!insert_node(a, ft_atoi(split[i])))
				return (free_stacks(a, b, &split, 0));
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

		if ((argc > 2 && (!argv[1][0] || !argv[2][0])) || (argc == 2 && !argv[1][0]))
			return (ft_putstr_fd("Error\n", 2), 0);
		stack_a = init_stack();
		stack_b = init_stack();
		if (argc == 2)
		{
			if (!convert_split(argc, argv, &stack_a, &stack_b))
				return (ft_putstr_fd("Error\n", 2), 0);
		}
		else if (!check_duplicates(&stack_a, argc, argv))
			return (ft_putstr_fd("Error\n", 2), 0);
		push_swap(&stack_a, &stack_b);

		free_stack(&stack_b);
		free_stack(&stack_a);
	}
	return (0);
}
