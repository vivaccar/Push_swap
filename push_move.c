/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:14:50 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/18 21:03:14 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	push(t_stack **out, t_stack **in) 
{
	t_stack	*push_node;
 
	if (!*out)
		return ;
	push_node = *out; 
	*out = (*out)->next;
	if (*out)
		(*out)->prev = NULL;
	push_node->prev = NULL;
	if (!*in)
	{
		*in = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *in;
		push_node->next->prev = push_node;
		*in = push_node;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write (1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write (1, "pb\n", 3);
}