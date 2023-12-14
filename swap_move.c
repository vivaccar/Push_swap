/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:26:12 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/14 20:14:10 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack **a)
{
	swap(a);
	write (1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	write (1, "sb\n", 3);	
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write (1, "ss\n", 3);
}
