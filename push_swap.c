/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:17:33 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/28 10:47:47 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **head)
{
	t_stack	*big;

	big = find_big(*head);
	if (big == *head)
		ra(head, 1);
	else if (big == (*head)->next)
		rra(head, 1);
	if (!stack_is_sorted(*head))
		sa(head, 1);
}

void	push_swap(t_stack **stack_a)
{
	t_stack		*stack_b;

	stack_b = NULL;
	if (!stack_is_sorted(*stack_a))
	{
		if (stack_size(*stack_a) == 2)
			sa(stack_a, 1);
		if (stack_size(*stack_a) == 3)
			sort_three(stack_a);
		if (stack_size(*stack_a) > 3)
		{
			start_b(stack_a, &stack_b);
			sort_three(stack_a);
		}
		push_to_a(stack_a, &stack_b);
		min_on_top(stack_a);
	}
}
