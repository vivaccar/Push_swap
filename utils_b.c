/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinivaccari <vinivaccari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:16:51 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/24 13:49:19 by vinivaccari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_on_top(t_stack **stack_a)
{
	t_stack	*min;

	min = find_min(*stack_a);
	get_index_med(stack_a);
	while (*stack_a != min)
	{
		if (min->before_med)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
}

void	max_on_top(t_stack **stack)
{
	t_stack		*big;

	big = find_big(*stack);
	while (*stack != big)
	{
		if (big->before_med)
			rb(stack, 1);
		else
			rrb(stack, 1);
	}
}

t_stack	*find_min(t_stack *stack)
{
	int	i;
	t_stack	*min;
	
	i = INT_MAX;
	while (stack)
	{
		if (stack->value < i)
		{
			i = stack->value;
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}