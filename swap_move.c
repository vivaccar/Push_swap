/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinivaccari <vinivaccari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:26:12 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/24 12:53:45 by vinivaccari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head)
{
	if (!*head || !(*head)->next)
		return;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack **a, int flag)
{
	swap(a);
	if (flag == 1)
		write (1, "sa\n", 3);
}

void	sb(t_stack **b, int flag)
{
	swap(b);
	if (flag == 1)
		write (1, "sb\n", 3);	
}

void	ss(t_stack **a, t_stack **b, int flag)
{
	swap(a);
	swap(b);
	if (flag == 1)
		write (1, "ss\n", 3);
}
