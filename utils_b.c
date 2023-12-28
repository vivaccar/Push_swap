/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:16:51 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/28 10:53:56 by vivaccar         ###   ########.fr       */
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
	int		i;
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

void	get_target(t_stack **a, t_stack **b)
{
	t_stack		*tmp;
	t_stack		*cur_b;
	int			cur_match;

	tmp = *a;
	while (tmp)
	{
		cur_match = INT_MIN;
		cur_b = *b;
		while (cur_b)
		{
			if (cur_b->value > cur_match && cur_b->value < tmp->value)
			{
				tmp->target = cur_b;
				cur_match = cur_b->value;
			}
			cur_b = cur_b->next;
		}
		if (cur_match == INT_MIN)
			tmp->target = find_big(*b);
		tmp = tmp->next;
	}
}
