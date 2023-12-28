/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:54:41 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/28 11:13:00 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		op = get_next_line(0);
		if (op == NULL)
			break ;
		do_ops(op, stack_a, &stack_b);
		free(op);
	}
	if (stack_is_sorted(*stack_a) && stack_b == NULL)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	ft_free(stack_a);
	ft_free(&stack_b);
}
