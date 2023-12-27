/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:12:06 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/27 11:28:45 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **head)
{
	t_stack	*last_node;

	if (*head == NULL || (*head)->next == NULL)
		return ;
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