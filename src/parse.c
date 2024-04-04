/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:24:26 by nraymond          #+#    #+#             */
/*   Updated: 2024/04/04 14:28:55 by nraymond         ###   ########.fr       */
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



int	check_duplicates(t_stack **stack_a, int argc, char **argv)
{
	int	i;
	int	k;
	int	val;

	i = argc - 1;
	while (i)
	{
		k = i - 1;
		val = ft_atoi(argv[i]);
		if (!check_input(argv[i]) || !val && argv[i][0] != '0')
			return (0);
		if (!insert_node(stack_a, val))
			return (0);
		while (k)
		{
			if (!ft_atoi(argv[k]) && argv[k][0] != '0')
				return (0);
			if (val == ft_atoi(argv[k]))
				return (0);
			k--;
		}
		i--;
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
