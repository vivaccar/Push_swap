/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:04:38 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/28 11:10:17 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_2(t_stack **stack_a, t_stack **stack_b, t_stack *cheap_node)
{
	while (*stack_a != cheap_node && *stack_b != cheap_node->target)
		rr(stack_a, stack_b, 1);
	while (*stack_a != cheap_node)
		ra(stack_a, 1);
	while (*stack_b != cheap_node->target)
		rb(stack_b, 1);
}

void	r_rot_2(t_stack **stack_a, t_stack **stack_b, t_stack *cheap_node)
{
	while (*stack_a != cheap_node && *stack_b != cheap_node->target)
		rrr(stack_a, stack_b, 1);
	while (*stack_a != cheap_node)
		rra(stack_a, 1);
	while (*stack_b != cheap_node->target)
		rrb(stack_b, 1);
}

void	ra_rrb(t_stack **stack_a, t_stack **stack_b, t_stack *cheap_node)
{
	while (*stack_a != cheap_node)
		ra(stack_a, 1);
	while (*stack_b != cheap_node->target)
		rrb(stack_b, 1);
}

void	rra_rb(t_stack **stack_a, t_stack **stack_b, t_stack *cheap_node)
{
	while (*stack_a != cheap_node)
		rra(stack_a, 1);
	while (*stack_b != cheap_node->target)
		rb(stack_b, 1);
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheap_node;

	cheap_node = set_cheapest(stack_a);
	if ((cheap_node->before_med) && (cheap_node->target->before_med))
		rotate_2(stack_a, stack_b, cheap_node);
	else if (!(cheap_node->before_med)
		&& !(cheap_node->target->before_med))
		r_rot_2(stack_a, stack_b, cheap_node);
	else if (cheap_node->before_med && !(cheap_node->target->before_med))
		ra_rrb(stack_a, stack_b, cheap_node);
	else 
		rra_rb(stack_a, stack_b, cheap_node);
}
