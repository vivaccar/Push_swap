/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinivaccari <vinivaccari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:12:06 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/24 12:55:08 by vinivaccari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **head)
{
	t_stack	*last_node;

	last_node = find_last(*head);
	last_node->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack **stack_a, int flag)
{
	rotate(stack_a);
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack	**stack_b, int flag)
{
	rotate(stack_b);
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int flag)
{
	rotate(stack_a);
	rotate(stack_b);
	if (flag == 1)
		write (1, "rr\n", 3);
}