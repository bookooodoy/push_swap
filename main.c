/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:21:56 by nraymond          #+#    #+#             */
/*   Updated: 2024/01/31 11:52:28 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my-libft/headers/libft.h"

int	check_valid_values(char *integer)
{
	int		i;
	long int 	range;
	int		sign;
	int		count;

	count = 0;
	i = 0;
	if (!integer)
		return (0);
	while (integer[i])
	{
		range = 0;
		while (ft_isdigit(integer[i]))
		{
			range = (10 * range) + integer[i] - '0';
			i++;
		}
		if (integer[i] != ' ')
			return (0);
		// check for range overflow
		if (range < -2147483648 || range > 2147483647)
			return (0);
		i++;
		count++;
	}
	return (count);
}

int	get_duplicates_tab(int len, char *integer)
{
	int	i;
	int	c;
	int	num;
	int	*tab;
	
	c = 0;
	i = 0;
	if (!integer)
		return (0);
	tab = malloc(sizeof(int) * len + 1);
	if (!tab)
		return (0);
	while (integer[i])
	{
		num = 0;
		while (ft_isdigit(integer[i]))
		{
			num = (10 * num) + integer[i] - '0';
			i++;
		}
		// add the value to the tab
		tab[c++] = num;
		i++;
	}
	return (tab);
}

int	check_duplicate(int *tab, int len)
{
	int	i;
	int	k;

	i = 0;
	while (i < len)
	{
		k = i;
		while (++k < len)
			if (tab[i] == tab[k])
				return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	l;
		int	*tab;
		l = check_valid_values(argv[1]);
		if (l)
		{
			tab = get_duplicates_tab(l, argv[1]);
			if (!check_duplicate(tab, len))
			{
				free(tab);
				tab = NULL;
				return (ft_printf("Error\n"), exit(-1));
			}
			// execute push_swap

		}
		return (exit(0));
	}
	return (ft_printf("Error\n"), exit(-1));
}
