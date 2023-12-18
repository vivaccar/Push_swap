/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:17:33 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/18 21:59:50 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **head)
{
	t_stack	*big;

	big = find_big(*head);
	if (big == *head)
		ra(head);
	else if (big == (*head)->next)
		rra(head);
	if (!stack_is_sorted(*head))
		sa(head);
}
