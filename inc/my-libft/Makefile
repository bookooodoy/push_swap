SRCS:= src/libft/ft_atoi.c\
       src/libft/ft_isascii.c\
       src/libft/ft_memcmp.c\
       src/libft/ft_putendl_fd.c\
       src/libft/ft_strdup.c\
       src/libft/ft_strlen.c\
       src/libft/ft_strtrim.c\
       src/libft/ft_bzero.c\
       src/libft/ft_isdigit.c\
       src/libft/ft_memcpy.c\
       src/libft/ft_putnbr_fd.c\
       src/libft/ft_striteri.c\
       src/libft/ft_strmapi.c\
       src/libft/ft_substr.c\
       src/libft/ft_calloc.c\
       src/libft/ft_isprint.c\
       src/libft/ft_memmove.c\
       src/libft/ft_putstr_fd.c\
       src/libft/ft_strjoin.c\
       src/libft/ft_strncmp.c\
       src/libft/ft_tolower.c\
       src/libft/ft_isalnum.c\
       src/libft/ft_itoa.c\
       src/libft/ft_memset.c\
       src/libft/ft_split.c\
       src/libft/ft_strlcat.c\
       src/libft/ft_strnstr.c\
       src/libft/ft_toupper.c\
       src/libft/ft_isalpha.c\
       src/libft/ft_memchr.c\
       src/libft/ft_putchar_fd.c\
       src/libft/ft_strchr.c\
       src/libft/ft_strlcpy.c\
       src/printf/ft_printf.c\
       src/printf/ft_parse.c\
       src/printf/convert_args.c\
       src/printf/convert_chars.c\
       src/printf/convert_integers.c\
       src/printf/convert_precision_buff.c\
       src/printf/convert_fwidth_buff.c\
       src/printf/append_flags.c\
       src/gnl/get_next_line_utils_bonus.c\
       src/gnl/get_next_line_bonus.c

INCL=inc/libft.h

OBJ=$(SRCS:.c=.o)

CFLAGS=-Werror -Wextra -Wall -I .

CC=cc

NAME=libft.a

all: $(NAME)

$(NAME): $(OBJ) $(INCL) Makefile
	ar -rcs $(NAME) $(OBJ)

%.o : %.c $(INCL) Makefile
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
