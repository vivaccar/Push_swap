/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:07:35 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/23 16:16:36 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
	{
		set_datas_b(stack_a, stack_b);
		while (*stack_a != (*stack_b)->target)
		{
			if ((*stack_b)->target->before_med)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pa(stack_a, stack_b);
	}
}

void	set_datas_b(t_stack **stack_a, t_stack **stack_b)
{
	get_index_med(stack_a);
	get_index_med(stack_b);
	get_target_b(stack_a, stack_b);
}

void	get_target_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*cur_a;
	t_stack *target_node;
	long		cur_match;
	
	tmp = *stack_b;
	while (tmp)
	{
		cur_match = LONG_MAX;
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
		if(cur_match == LONG_MAX)
			tmp->target = find_min(*stack_a);
		else
			tmp->target = target_node;
		tmp = tmp->next;
	}
}