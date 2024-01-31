/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:49:35 by nraymond          #+#    #+#             */
/*   Updated: 2024/01/31 11:07:47 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

#  if BUFFER_SIZE > 10000000000
#	undef BUFFER_SIZE
#	define BUFFER_SIZE 0
#  endif

# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct t_prt
{
	char			*buffer;
	char			*flags;
	char			cflag;
	unsigned int	fwidth;
	int				precision;
}	t_prt;

typedef struct l_list
{
	char			*val;
	struct l_list	*next;
}	t_list;

// printf functions
void	append_hashtag(t_prt *object);
void	append_plus(char **buffer);
void	append_space(char **buffer);
void	append_zeroes(size_t bufferlen, char **buffer, int fwidth);
void	append_flags(t_prt *object);
unsigned int	get_uintlen(unsigned int x);
char	*convert_x(unsigned int x, char *base);
int	get_plen(void *p);
char	*convert_arg_p(void *p, char *base);
int	ft_putchar(char c);
int	ft_putstr(char *s);
char	*convert_c(const char c);
char	*convert_s(const char *s);
int	prt_spaces(unsigned int lenght);
unsigned int	get_range(char *s);
int	convert_fwidth_negative(t_prt *object, unsigned int lenght);
int	convert_fwidth_nflag(t_prt *object, unsigned int lenght);
int	convert_fwidth_buffer(t_prt *object);
size_t	count_digit_length(unsigned int n);
char	*ft_uitoa(unsigned int n);
char	*convert_d_i(int i);
int	is_zero(char *buf);
int	get_precision(char *s);
char	*convert_from_flag(char cflag, va_list vargs);
void	convert_precision_buffer_sflag(t_prt *object);
void	convert_precision_buffer(t_prt *object);
int	is_valid_param(const char c, const char *valid_params);
char	get_cflag(const char *s);
char	*get_flags(char *s);
char	*overwrite_flags(char *flags, char ignored);
char	*parse_legal_flags(char *flags, char cflag);
void	free_t_prt(t_prt **object);
int	init_params(char *s, va_list vargs);
int	get_prt_objsize(t_prt **object);
int	ft_convert_cflag(const char *s, int *i, va_list vargs);
int	ft_printf(const char *s, ...);
char	*check_last_empty(t_list **head, char **buffer, char **line, int len);
int	lst_add_last(t_list **head, char *new_data);
int	get_end_line(t_list **head, char **buffer);
char	*extract_line(t_list **head, char **buffer, int len);
char	*get_next_line(int fd);
void	add_last_char(char *dst, const char *src, char *buffer);
void	free_all(t_list **head, char **buffer, char **line);
char	*ft_strcpy(char *dst, const char *src);
int	ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, int n);
int	ft_memcmp(const void *s1, const void *s2, int n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	ft_tolower(int c);
int	ft_toupper(int c);

#endif
