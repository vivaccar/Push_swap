/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinivaccari <vinivaccari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:04:38 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/24 13:48:18 by vinivaccari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ab(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
	while (*stack_a != cheapest_node && *stack_b != cheapest_node->target)
		rr(stack_a, stack_b, 1);
	while (*stack_a != cheapest_node)
		ra(stack_a, 1);
	while (*stack_b != cheapest_node->target)
		rb(stack_b, 1);
}

void	rev_rotate_ab(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
	while (*stack_a != cheapest_node && *stack_b != cheapest_node->target)
		rrr(stack_a, stack_b, 1);
	while (*stack_a != cheapest_node)
		rra(stack_a, 1);
	while (*stack_b != cheapest_node->target)
		rrb(stack_b, 1);
}

void	ra_and_rrb(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
	while (*stack_a != cheapest_node)
		ra(stack_a, 1);
	while (*stack_b != cheapest_node->target)
		rrb(stack_b, 1);
}

void	rra_and_rb(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
	while (*stack_a != cheapest_node)
		rra(stack_a, 1);
	while (*stack_b != cheapest_node->target)
		rb(stack_b, 1);
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;
	
	cheapest_node = set_cheapest(stack_a);
	if ((cheapest_node->before_med) && (cheapest_node->target->before_med))
		rotate_ab(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->before_med) && !(cheapest_node->target->before_med))
		rev_rotate_ab(stack_a, stack_b, cheapest_node);
	else if (cheapest_node->before_med && !(cheapest_node->target->before_med))
		ra_and_rrb(stack_a, stack_b, cheapest_node);
	else 
		rra_and_rb(stack_a, stack_b, cheapest_node);		
}