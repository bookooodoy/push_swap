SRCS=operations.c\
    
INCL=push_swap.h

MAIN=main.c

NAME=push_swap

CC=cc

CFLAGS=-Wall -Wextra -Werror -I .

LIBFT=my-libft/

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT)

$(MAME): $(main)

$(name):
	$(CC) $(CFLAGS) -o $(NAME)

