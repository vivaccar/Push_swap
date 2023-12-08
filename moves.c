/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:26:12 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/08 18:26:40 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head)
{
	if (!*head || !(*head)->next)
		return;
	*head = (*head)->next;
	(*head)->next = (*head)->prev;
	(*head)->next->prev = *head;
	(*head)->next->next = NULL;
}

void	sa(t_stack **a)
{
	swap(a);
	write (1, "sa\n", 3);
}