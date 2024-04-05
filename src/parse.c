/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:24:26 by nraymond          #+#    #+#             */
/*   Updated: 2024/04/05 15:29:35 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/push_swap.h"
#include "../inc/my-libft/inc/libft.h"

int	free_stacks(t_stack **a, t_stack **b, char ***split, int no_cap)
{
	int	i;

	if (!no_cap)
	{
		free_stack(a);
		free_stack(b);
	}
	if (!*split)
		return (0);
	i = 0;
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

int	check_input(char *s)
{
	int	i;

	if (!s || ((ft_atoi(s) == 0 && s[0] != '0') || (ft_atoi(s) == 0 && ft_strlen(s) > 1)))
		return (0);
	i = 0;
	while (s[i])
	{
		if ((i == 0 && !ft_isdigit(s[i])) && s[i] != '-')
			return (0);
		else if (i > 0 && !ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_dup(char **arg, int start)
{
	int	i;
	int	k;

	i = start;
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

int	check_duplicates(t_stack **stack_a, int argc, char **argv, int start)
{
	int	val;

	if (!check_dup(argv, start))
		return (0);
	argc-= 1;
	while (argc != -1)
	{
		val = ft_atoi(argv[argc]);
		if (!insert_node(stack_a, val))
			return (0);
		argc--;
	}
	return (1);
}

int	convert_split(char **argv, t_stack **a, t_stack **b)
{
	char	**split;
	int	c;

	split = ft_split(argv[1], ' ');
	if (!split)
		return (free_stacks(a, b, &split, 0));
	c = 0;
	while (split[c])
		c++;
	if (!check_duplicates(a, c, split, 0))
		return (free_stacks(a, b, &split, 0));
	return (free_stacks(a, b, &split, 1));
}
