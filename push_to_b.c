/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:04:38 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/21 21:45:37 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ab(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
	while (*stack_a != cheapest_node && *stack_b != cheapest_node->target)
		rr(stack_a, stack_b);
	while (*stack_a != cheapest_node)
		ra(stack_a);
	while (*stack_b != cheapest_node->target)
		rb(stack_b);
}

void	rev_rotate_ab(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
	while (*stack_a != cheapest_node && *stack_b != cheapest_node->target)
		rrr(stack_a, stack_b);
	while (*stack_a != cheapest_node)
		rra(stack_a);
	while (*stack_b != cheapest_node->target)
		rrb(stack_b);
}

void	ra_and_rrb(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
	while (*stack_a != cheapest_node)
		ra(stack_a);
	while (*stack_b != cheapest_node->target)
		rrb(stack_b);
}

void	rra_and_rb(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
	while (*stack_a != cheapest_node)
		rra(stack_a);
	while (*stack_b != cheapest_node->target)
		rb(stack_b);
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;
	
	cheapest_node = set_cheapest(stack_a);
	//printf("Cheapest Node: %i, Cheap Cost: %i, Before: %i, Target: %i\n", cheapest_node->value, cheapest_node->cost, cheapest_node->before_med, cheapest_node->target->value);
	if ((cheapest_node->before_med) && (cheapest_node->target->before_med))
		rotate_ab(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->before_med) && !(cheapest_node->target->before_med))
		rev_rotate_ab(stack_a, stack_b, cheapest_node);
	else if (cheapest_node->before_med && !(cheapest_node->target->before_med))
		ra_and_rrb(stack_a, stack_b, cheapest_node);
	else 
		rra_and_rb(stack_a, stack_b, cheapest_node);		
}