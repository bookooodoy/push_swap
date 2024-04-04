SRCS=src/main.c\
     src/utils.c\
     src/sort.c\
     src/parse.c\
     src/push.c\
     src/rotate.c\
     src/stack.c\
     src/swap.c\
     src/count.c\
     src/median.c\
     src/search_small.c\
     src/search_big.c

INC=inc/headers/push_swap.h\
    inc/my-libft/inc/libft.h

INCPATH=inc/my-libft/

LIBFT=$(INCPATH)libft.a

CC=cc

CFLAGS=-Werror -Wall -Wextra -g3

NAME=push_swap

all: $(NAME)

$(NAME): $(LIBFT) $(INC) Makefile $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIBFT)

$(LIBFT): $(INC) Makefile
	$(MAKE) -C $(INCPATH)

clean:
	$(MAKE) clean -C $(INCPATH)

fclean: clean
	$(MAKE) fclean -C $(INCPATH)
	$(RM) -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
