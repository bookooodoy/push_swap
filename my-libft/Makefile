SRCS=src/ft_printf/append_flags.c\
     src/ft_printf/convert_args.c\
     src/ft_printf/convert_chars.c\
     src/ft_printf/convert_fwidth_buff.c\
     src/ft_printf/convert_integers.c\
     src/ft_printf/convert_precision_buff.c\
     src/ft_printf/ft_parse.c\
     src/ft_printf/ft_printf.c\
     src/get_next_line/get_next_line_bonus.c\
     src/get_next_line/get_next_line_utils_bonus.c\
     src/libft/ft_atoi.c\
     src/libft/ft_bzero.c\
     src/libft/ft_calloc.c\
     src/libft/ft_isalnum.c\
     src/libft/ft_isalpha.c\
     src/libft/ft_isascii.c\
     src/libft/ft_isdigit.c\
     src/libft/ft_isprint.c\
     src/libft/ft_itoa.c\
     src/libft/ft_memchr.c\
     src/libft/ft_memcmp.c\
     src/libft/ft_memcpy.c\
     src/libft/ft_memmove.c\
     src/libft/ft_memset.c\
     src/libft/ft_putchar_fd.c\
     src/libft/ft_putendl_fd.c\
     src/libft/ft_putnbr_fd.c\
     src/libft/ft_putstr_fd.c\
     src/libft/ft_split.c\
     src/libft/ft_strchr.c\
     src/libft/ft_strdup.c\
     src/libft/ft_striteri.c\
     src/libft/ft_strjoin.c\
     src/libft/ft_strlcat.c\
     src/libft/ft_strlcpy.c\
     src/libft/ft_strlen.c\
     src/libft/ft_strmapi.c\
     src/libft/ft_strncmp.c\
     src/libft/ft_strnstr.c\
     src/libft/ft_strrchr.c\
     src/libft/ft_strtrim.c\
     src/libft/ft_substr.c\
     src/libft/ft_tolower.c\
     src/libft/ft_toupper.c

OBJ=$(SRCS:.c=.o)

headers=inc/libft.h

HEADERPATH=inc

NAME=libft.a

CC=cc

CFLAGS=-Wall -Wextra -Werror -I .

all: $(NAME)

$(NAME): $(OBJ) $(headers) Makefile
	ar -rcs $(NAME) $(OBJ)

%.o : %.c $(INCL) Makefile $(headers)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	$(RM) -rf $(OBJ)

fclean: clean
	$(RM) -rf $(NAME)

re: clean fclean

.PHONY: re fclean clean
