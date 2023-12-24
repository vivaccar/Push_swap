/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinivaccari <vinivaccari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:07:35 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/24 13:00:52 by vinivaccari      ###   ########.fr       */
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
				ra(stack_a, 1);
			else
				rra(stack_a, 1);
		}
		pa(stack_a, stack_b, 1);
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