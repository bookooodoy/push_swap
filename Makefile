SRCS=src/main.c\
     src/utils.c\
     src/operations.c

INC=inc/headers/push_swap.h\
    inc/my-libft/inc/libft.h

INCPATH=inc/my-libft/

LIBFT=$(INCPATH)libft.a

CC=cc

CFLAGS=-Werror -Wall -Wextra

NAME=push_swap

all: Makefile $(SRCS)
	$(CC) $(SRCS) -g3 -o $(NAME)

$(NAME): $(LIBFT) $(INCL) Makefile $(SRCS)
	$(CC) $(SRCS) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

$(LIBFT): $(INCL) Makefile
	$(MAKE) -C $(INCPATH)

clean:
	$(MAKE) clean -C $(INCPATH)
	$(MAKE) clean -C $(MLX)

fclean: clean
	$(MAKE) fclean -C $(INCPATH)
	$(RM) -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
