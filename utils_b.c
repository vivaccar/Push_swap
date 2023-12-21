/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:16:51 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/21 20:46:47 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	get_target_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*cur_a;
	t_stack *target_node;
	int		cur_match;
	
	tmp = *stack_b;
	while (tmp)
	{
		cur_match = INT_MAX;
		cur_a = *stack_a;
		while (cur_a)
		{
			if(cur_a->value < cur_match && tmp->value < cur_a->value)
			{
				target_node = cur_a;
				cur_match = cur_a->value;
			}
			cur_a = cur_a->next;
		}	
		if(cur_match == INT_MAX)
			tmp->target = find_min(*stack_a);
		else
			tmp->target = target_node;
		tmp = tmp->next;
	}
}