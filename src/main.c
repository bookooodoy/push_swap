/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:24:19 by nraymond          #+#    #+#             */
/*   Updated: 2024/04/04 16:29:58 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/push_swap.h"
#include "../inc/my-libft/inc/libft.h"

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
