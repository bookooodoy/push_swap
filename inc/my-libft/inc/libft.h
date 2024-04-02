#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

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

//printf
unsigned int	get_uintlen(unsigned int x);
char			*convert_arg_p(void *p, char *base);
char			*convert_x(unsigned int x, char *base);
char			*convert_s(const char *s);
char			*convert_c(const char c);
char			*convert_d_i(int i);
char			*convert_from_flag(char cflag, va_list vargs);
char			*get_flags(char *s);
char			*ft_uitoa(unsigned int n);
int				ft_printf(const char *s, ...);
int				ft_putchar(char c);
int				ft_putstr(char *s);
int				get_plen(void *p);
void			free_t_prt(t_prt **object);
void			convert_precision_buffer(t_prt *object);
int				convert_fwidth_buffer(t_prt *object);
void			append_flags(t_prt *object);
int				is_valid_param(const char c, const char *valid_params);
char			get_cflag(const char *s);
unsigned int	get_fwidth(char *s);
unsigned int	get_range(char *s);
char			*overwrite_flags(char *flags, char ignored);
char			*parse_legal_flags(char *flags, char cflag);
void			append_zeroes(size_t bufferlen, char **buffer, int fwidth);
int				get_prt_objsize(t_prt **object);
int				is_zero(char *buf);
int				get_precision(char *s);

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, int n);
int		ft_memcmp(const void *s1, const void *s2, int n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// main
char	*check_last_empty(t_list **head, char **buffer, char **line, int len);
char	*get_next_line(int fd);
int		lst_add_last(t_list **head, char *new_data);
int		get_end_line(t_list **head, char **buffer);
char	*extract_line(t_list **head, char **buffer, int len);

// utils
void	add_last_char(char *dst, const char *src, char *buffer);
void	free_all(t_list **head, char **buffer, char **line);

#endif
