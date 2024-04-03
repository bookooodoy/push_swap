#include "../inc/headers/push_swap.h"
#include "../inc/headers/checker.h"

char	*update_buff(char **buf, char *new_line)
{
	char	*nl;

	nl = ft_strjoin(*buf, new_line);
	free(*buf);
	*buf = nl;
}

char	*read_instructions()
{
	char	*l;
	char	*buf;

	l = get_next_line(0);
	while (l)
	{
		update_buff(&buf, l);
		free(l);
		l = get_next_line(0);
	}
	free(l);
	ft_printf("%s", buf);
	return (buf);
}

int	main(int argc, char **argv)
{	
	(void)argc;
	(void)argv;
	read_instructions();
}
