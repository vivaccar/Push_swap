SRCS	=	check_input.c start_stack.c utils.c \
			push_swap.c push_move.c rev_rotate_move.c rotate_move.c \
			swap_move.c set_datas.c push_to_b.c utils_b.c push_to_a.c

BONUS	=	bonus/checker.c \
			bonus/checker_utils.c \
			bonus/get_next_line/get_next_line.c \
			bonus/get_next_line/get_next_line_utils.c

OBJS	=	$(SRCS:.c=.o)

B_OBJS	=	$(BONUS:.c=.o)

CC		=	cc

NAME	=	push_swap

NAME_B	=	checker

CFLAGS  = 	-Wall -Wextra -Werror -g

LIBFTA  = 	./Libft/libft.a

LIBFTD  = 	./Libft

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTA)
	$(CC) main.c $(CFLAGS) $(OBJS) $(LIBFTA) -o $(NAME)

bonus: $(NAME_B) 

$(NAME_B): $(OBJS) $(B_OBJS) $(LIBFTA)
	$(CC) $(CFLAGS) $(OBJS) $(B_OBJS) $(LIBFTA) -o $(NAME_B)

clean:
	rm -f $(B_OBJS)
	rm -f $(OBJS)
	make clean -C $(LIBFTD)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_B)
	make fclean -C $(LIBFTD)

re: fclean all

$(LIBFTA): $(LIBFTD)
	make -C $(LIBFTD)