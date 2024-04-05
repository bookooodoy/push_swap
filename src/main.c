/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:24:19 by nraymond          #+#    #+#             */
/*   Updated: 2024/04/05 16:25:42 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/push_swap.h"
#include "../inc/my-libft/inc/libft.h"

int	init_stacks(t_stack **a, t_stack **b)
{
	*a = init_stack();
	if (!*a)
		return (0);
	*b = init_stack();
	if (!*b)
		return (free(*a), 0);
	return (1);
}

int	check_valid_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!argv[i] || !argv[i][0]) // NULL argument
			return (0);
		i++;
	}
	return (1);
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (!check_valid_args(argc, argv))
		return (ft_putstr_fd("Error\n", 2), 1);
	if (!init_stacks(&a, &b))
		return (1);
	if (argc == 2)
	{
		if (!convert_split(argv, &a, &b))
			return (ft_putstr_fd("Error\n", 2), 1);
	}
	else if (argc > 2)
	{
		if (!check_duplicates(&a, argc, argv, 1))
		{
			free_stack(&a);
			free_stack(&b);
			return (ft_putstr_fd("Error\n", 2), 1);
		}
	}
	solve(&a, &b);
	return (0);
}
