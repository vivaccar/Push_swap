/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:16:51 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/23 16:16:50 by vivaccar         ###   ########.fr       */
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
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	max_on_top(t_stack **stack)
{
	t_stack		*big;

	big = find_big(*stack);
	t_stack *tmp = *stack;
	//printf ("STACK B ANTES DE COLOCAR O MAIOR NO TOPO:\n");
	//printf ("Big: %i\n", big->value);
	while (tmp)
	{
		//printf("Value: %i, Index: %i, Before median: %i\n", tmp->value, tmp-> index, tmp->before_med);
		tmp = tmp->next;	
	}
	while (*stack != big)
	{
		if (big->before_med)
			rb(stack);
		else
			rrb(stack);
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