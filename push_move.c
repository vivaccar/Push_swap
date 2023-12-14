/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:14:50 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/14 20:15:29 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **out, t_stack **in)
{
	t_stack	*tmp;

	if (!*out)
		return ;
	tmp = *in;
	*in = *out;
	*out = (*out)->next;
	(*in)->next = tmp;
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