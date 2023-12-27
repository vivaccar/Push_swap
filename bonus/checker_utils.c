#include "checker.h"

void	input_error(char *op, t_stack **stack_a, t_stack **stack_b)
{
	if (op[0] == '\n' && !op[1])
		return ;
	ft_free(stack_a);
	ft_free(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

void	do_ops(char *op, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		sa(stack_a, 0);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		sb(stack_b, 0);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		ra(stack_a, 0);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		rb(stack_b, 0);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		rra(stack_a, 0);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		rrb(stack_b, 0);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b, 0);
	else
		input_error(op, stack_a, stack_b);
}

void	read_commands(t_stack **stack_a)
{
	char	*op;
	t_stack	*stack_b;

	op = NULL;
	stack_b = NULL;
	while (1)
	{
		do_ops(op = get_next_line(0), stack_a, &stack_b);
		if (op[0] == '\n')
			break;
		free(op);
	}
	free(op);
	if (stack_is_sorted(*stack_a) && stack_b == NULL)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	ft_free(stack_a);
	ft_free(&stack_b);
}