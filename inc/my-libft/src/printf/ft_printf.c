/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:51:34 by nraymond          #+#    #+#             */
/*   Updated: 2024/01/30 22:40:56 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	free_t_prt(t_prt **object)
{
	if (!*object)
		return ;
	if ((*object)->buffer)
	{
		free((*object)->buffer);
		(*object)->buffer = NULL;
	}
	if ((*object)->flags)
	{
		free((*object)->flags);
		(*object)->flags = NULL;
	}
	free(*object);
	*object = NULL;
}

int	init_params(char *s, va_list vargs)
{
	t_prt	*object;
	char	*flags;
	int		c;

	object = malloc(sizeof(t_prt));
	if (!object)
		return (-1);
	object->cflag = get_cflag(s);
	if (!object->cflag)
		return (free_t_prt(&object), -1);
	flags = get_flags(s);
	if (flags)
	{
		object->flags = parse_legal_flags(flags, object->cflag);
		if (!object->flags)
			return (free_t_prt(&object), -1);
	}
	object->fwidth = get_range(s);
	object->precision = get_precision(s);
	object->buffer = convert_from_flag(object->cflag, vargs);
	if (!object->buffer)
		return (free_t_prt(&object), -1);
	c = get_prt_objsize(&object);
	return (free_t_prt(&object), c);
}

int	get_prt_objsize(t_prt **object)
{
	if (!*object)
		return (-1);
	if (((*object)->precision != -1))
		convert_precision_buffer(*object);
	if ((*object)->flags)
		append_flags(*object);
	if ((*object)->fwidth)
		return (convert_fwidth_buffer(*object));
	if ((*object)->cflag == 'c')
		return (ft_putchar(*((*object)->buffer)));
	return (ft_putstr((*object)->buffer));
}

int	ft_convert_cflag(const char *s, int *i, va_list vargs)
{
	char	*substr;
	int		c;

	if (s[++(*i)] == '%')
		return (ft_putchar(s[*i]));
	else if (is_valid_param(s[*i], "cspdiuxX"))
	{
		substr = convert_from_flag(s[*i], vargs);
		if (!substr)
			return (-1);
		if (s[*i] == 'c')
			c = ft_putchar(*substr);
		else
			c = ft_putstr(substr);
	}
	else
	{
		substr = ft_substr(s, *i, ft_strlen(s));
		if (!substr)
			return (-1);
		c = init_params(substr, vargs);
		while (!is_valid_param(s[*i], "cspdiuxX") && s[*i])
			*i += 1;
	}
	return (free(substr), c);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		c;
	int		fc;
	va_list	vargs;

	va_start(vargs, s);
	i = 0;
	fc = 0;
	if (!s)
		return (va_end(vargs), 0);
	while (s[i])
	{
		if (s[i] == '%')
			c = ft_convert_cflag(s, &i, vargs);
		else
			c = ft_putchar(s[i]);
		if (c == -1)
			return (va_end(vargs), -1);
		fc += c;
		i++;
	}
	return (va_end(vargs), fc);
}

/*
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	int a, b;

	printf("\n==========%%c tests==========\n");
	a = ft_printf("(cus) : %c\n", 'c');
	b = printf("(lib) : %c\n", 'c');
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %c\n", 0);
	b = printf("(lib) : %c\n", 0);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %c\n", 150);
	b = printf("(lib) : %c\n", 150);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("%d %d\n", a, b);

	printf("\n==========%%c tests bonus==========\n");
	a = ft_printf("(cus) : %-c\n", 'c');
	b = printf("(lib) : %-c\n", 'c');
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %-10c\n", 0);
	b = printf("(lib) : %-10c\n", 0);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %-500c\n", 150);
	b = printf("(lib) : %-500c\n", 150);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("%d %d\n", a, b);

	printf("\n==========%%c* tests==========\n");
	a = ft_printf("(cus) : %s\n", "Hello World");
	b = printf("(lib) : %s\n", "Hello World");
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %s\n", "Hello World\n\n\t");
	b = printf("(lib) : %s\n", "Hello World\n\n\t");
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %s\n", "\0Hello World\n\n\t");
	b = printf("(lib) : %s\n", "\0Hello World\n\n\t");
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("%d %d\n", a, b);

	printf("\n==========%%c* tests bonus==========\n");
	a = ft_printf("(cus) : %-.7s\n", "Hello World");
	b = printf("(lib) : %-.7s\n", "Hello World");
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %-20.2s\n", "fdf\n\n\t");
	b = printf("(lib) : %-20.2s\n", "fdf\n\n\t");
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %500.s\n", "Hello\n\n\t");
	b = printf("(lib) : %500.s\n", "Hello\n\n\t");
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("%d %d\n", a, b);

	printf("\n==========%%d tests==========\n");
	a = ft_printf("(cus) : %d\n", INT_MAX);
	b = printf("(lib) : %d\n", INT_MAX);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %d\n", INT_MIN);
	b = printf("(lib) : %d\n", INT_MIN);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %d\n", 0);
	b = printf("(lib) : %d\n", 0);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("%d %d\n", a, b);

	printf("\n==========%%d tests bonus==========\n");
	a = ft_printf("(cus) : % 0d\n", INT_MAX);
	b = printf("(lib) : % 0d\n", INT_MAX);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : % -10.60d\n", INT_MIN);
	b = printf("(lib) : % -10.60d\n", INT_MIN);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %+- 05.d\n", 0);
	b = printf("(lib) : %+-5.d\n", 0);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %+- 05.97d\n", 0);
	b = printf("(lib) : %+-5.97d\n", 0);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("%d %d\n", a, b);

	printf("\n==========%%i tests==========\n");
	a = ft_printf("(cus) : %i\n", INT_MAX);
	b = printf("(lib) : %i\n", INT_MAX);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%i %i\n", a, b);
	a = ft_printf("(cus) : %i\n", INT_MIN);
	b = printf("(lib) : %i\n", INT_MIN);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%i %i\n", a, b);
	a = ft_printf("(cus) : %i\n", 0);
	b = printf("(lib) : %i\n", 0);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("%d %d\n", a, b);

	printf("\n==========%%i tests==========\n");
	a = ft_printf("(cus) : % 0i\n", INT_MAX);
	b = printf("(lib) : % 0i\n", INT_MAX);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%i %i\n", a, b);
	a = ft_printf("(cus) : % -10.20i\n", INT_MIN);
	b = printf("(lib) : % -10.20i\n", INT_MIN);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%i %i\n", a, b);
	a = ft_printf("(cus) : % +-5.i\n", 0);
	b = printf("(lib) : %+-5.i\n", 0);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("%d %d\n", a, b);

	printf("\n==========%%u tests==========\n");
	a = ft_printf("(cus) : %u\n", INT_MAX);
	b = printf("(lib) : %u\n", INT_MAX);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %u\n", INT_MIN);
	b = printf("(lib) : %u\n", INT_MIN);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %u\n", 0);
	b = printf("(lib) : %u\n", 0);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("%d %d\n", a, b);

	printf("\n==========%%u tests bonus==========\n");
	a = ft_printf("(cus) : %-010u\n", INT_MAX);
	b = printf("(lib) : %010u\n", INT_MAX);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %-10.20u\n", INT_MIN);
	b = printf("(lib) : %-10.20u\n", INT_MIN);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : % -5.u\n", 0);
	b = printf("(lib) : %-5.u\n", 0);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("%d %d\n", a, b);
	printf("\n==========%%x tests==========\n");
	a = ft_printf("(cus) : %x\n", INT_MAX);
	b = printf("(lib) : %x\n", INT_MAX);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %x\n", INT_MIN);
	b = printf("(lib) : %x\n", INT_MIN);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %x\n", 0);
	b = printf("(lib) : %x\n", 0);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("%d %d\n", a, b);

	printf("==========%%x tests bonus==========\n");
	a = ft_printf("(cus) : %#1000x\n", INT_MAX);
	b = printf("(lib) : %#1000x\n", INT_MAX);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %#-10.20x\n", INT_MIN);
	b = printf("(lib) : %#-10.20x\n", INT_MIN);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %-5.x\n", 0);
	b = printf("(lib) : %-5.x\n", 0);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("%d %d\n", a, b);
	printf("\n==========%%X tests==========\n");
	a = ft_printf("(cus) : %X\n", INT_MAX);
	b = printf("(lib) : %X\n", INT_MAX);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %X\n", INT_MIN);
	b = printf("(lib) : %X\n", INT_MIN);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %X\n", 0);
	b = printf("(lib) : %X\n", 0);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("%d %d\n", a, b);

	printf("\n==========%%X tests bonus==========\n");
	a = ft_printf("(cus) : %#1000X\n", INT_MAX);
	b = printf("(lib) : %#1000X\n", INT_MAX);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %#-10.20X\n", INT_MIN);
	b = printf("(lib) : %#-10.20X\n", INT_MIN);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %#-5.X\n", 0);
	b = printf("(lib) : %#-5.X\n", 0);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("%d %d\n", a, b);
	a = ft_printf("(cus) : %-20X\n", 0);
	b = printf("(lib) : %#-20X\n", 0);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("%d %d\n", a, b);

	printf("\n==========%%p tests==========\n");
	void *p = NULL;
	void *p1;
	int j = 1;
	p1 = &j;
	a = ft_printf("(cus) : %p\n", p);
	b = printf("(lib) : %p\n", p);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %p\n", p1);
	b = printf("(lib) : %p\n", p1);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : aw%pqeqwe\n", p1);
	b = printf("(lib) : aw%pqeqwe\n", p1);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : 0\n\n%p\n", p);
	b = printf("(lib) : 0\n\n%p\n", p);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("%d %d\n", a, b);

	printf("\n==========%%p tests bonus==========\n");
	a = ft_printf("(cus) : %1002p, %1520p\n", p, p1);
	b = printf("(lib) : %1002p, %1520p\n", p, p1);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %-120p, %150p\n", p, p1);
	b = printf("(lib) : %-120p, %150p\n", p, p1);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %-5p\n", p1);
	b = printf("(lib) : %-5p\n", p1);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %1002p, %1520p\n", p1, p);
	b = printf("(lib) : %1002p, %1520p\n", p1, p);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %-120p, %150p\n", p1, p);
	b = printf("(lib) : %-120p, %150p\n", p1, p);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %-5p\n", p);
	b = printf("(lib) : %-5p\n", p);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);

	printf("\n==========%% test==========\n");
	a = ft_printf("(cus) : %%c\n");
	b = printf("(lib) : %%c\n");
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %%%%c%%%c\n", 'A');
	b = printf("(lib) : %%%%c%%%c\n", 'A');
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	a = ft_printf("(cus) : %%d %dc\n", 150);
	b = printf("(lib) : %%d %dc\n", 150);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("%d %d\n", a, b);

	printf("\n==========mix test bonus==========\n");
	a = ft_printf
	("(cus) : %c %+20d %#x %-#2.100X,ppp %%p %p %.s, %-.3d", 65, 78954
		, INT_MAX, 2, p1, "j'adore 42", INT_MIN);
	printf("\n\n");
	b = printf("(lib) : %c %+20d %#x %-#2.100X,ppp %%p %p %.s, %-.3d", 65, 78954,
		INT_MAX, 2, p1, "j'adore 42", INT_MIN);
	if (a == b)
		printf("\033[0;32mTest passed!\033[0m");
	printf("\n%d %d\n", a, b);
	return 0;
}
*/
