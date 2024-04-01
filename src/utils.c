#include "../inc/headers/push_swap.h"

static int	ft_isdigit(char c)
{
	return (c >= 48 && c <= 57);
}

static int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long int	to_ret;

	to_ret = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		to_ret = (10 * to_ret) + (nptr[i] - '0');
		if (to_ret * sign > 2147483647 || to_ret * sign < -2147483648)
			return (0);
		i++;
	}
	return ((int)to_ret * sign);
}

void	free_stack(t_stack **stack)
{
	t_elem	*cur;
	t_elem	*next;

	if (!*stack)
		return ;
	cur = (*stack)->tail;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(*stack);
}

void	update_median(t_stack **s)
{
	if (!*s)
		return ;
	(*s)->median = (*s)->size / 2;
}
