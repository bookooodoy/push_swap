SRCS=src/main.c\
     src/utils.c\
     src/operations.c\
     src/sort.c

INC=inc/headers/push_swap.h\
    inc/my-libft/inc/libft.h

INCPATH=inc/my-libft/

LIBFT=$(INCPATH)libft.a

CC=cc

CFLAGS=-Werror -Wall -Wextra -g3

NAME=push_swap

all: $(NAME)

$(NAME): $(LIBFT) $(INCL) Makefile $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIBFT)

$(LIBFT): $(INCL) Makefile
	$(MAKE) -C $(INCPATH)

clean:
	$(MAKE) clean -C $(INCPATH)

fclean: clean
	$(MAKE) fclean -C $(INCPATH)
	$(RM) -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
