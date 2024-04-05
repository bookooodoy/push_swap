/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:24:19 by nraymond          #+#    #+#             */
/*   Updated: 2024/04/05 14:20:26 by nraymond         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (!check_valid_args(argc, argv))
		return (ft_putstr_fd("Error wth args\n", 2), 1);
	if (!init_stacks(&a, &b))
		return (1);
	if (argc == 2)
	{
		if (!convert_split(argv, &a, &b))
			return (ft_putstr_fd("Error with splt\n", 2), 1);
		ft_printf("2");
	}
	else if (argc > 2)
	{
		if (!check_duplicates(&a, argc, argv))
		{
			free_stack(&a);
			free_stack(&b);
			return (ft_putstr_fd("Error w dup\n", 2), 1);
		}
	}
	solve(&a, &b);
	return (0);
}
