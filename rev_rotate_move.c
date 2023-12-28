/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:13:43 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/28 10:54:23 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"	

void	r_rotate(t_stack **head)
{
	t_stack	*last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	last = find_last(*head);
	last->prev->next = NULL;
	last->next = *head;
	last->prev = NULL;
	*head = last;
	last->next->prev = last;
}

void	rra(t_stack **a, int flag)
{
	r_rotate(a);
	if (flag == 1)
		write (1, "rra\n", 4);
}

void	rrb(t_stack **b, int flag)
{
	r_rotate(b);
	if (flag == 1)
		write (1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int flag)
{
	r_rotate(a);
	r_rotate(b);
	if (flag == 1)
		write (1, "rrr\n", 4);
}
