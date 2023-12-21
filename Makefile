SRCS	=	push_swap.c check_input.c start_stack.c utils.c \
			sorts.c push_move.c rev_rotate_move.c rotate_move.c \
			swap_move.c set_datas.c push_to_b.c utils_b.c

OBJS	=	$(SRCS:.c=.o)

CC		=	cc

NAME	=	push_swap

CFLAGS  = -Wall -Wextra -Werror -g

LIBFTA  = ./Libft/libft.a

LIBFTD  = ./Libft

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTA)
	$(CC) -g $(CFLAGS) $(OBJS) $(LIBFTA) -o $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFTD)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTD)

re: fclean all

$(LIBFTA): $(LIBFTD)
	make -C $(LIBFTD)