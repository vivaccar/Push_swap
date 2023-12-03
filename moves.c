/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:28:39 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/03 17:54:32 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	stack_is_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack)
	{
		if (stack->value > stack->next->value)
			printf("%s", "not sorted");
			return (0);
		stack = stack->next;
	}
	return (1);
}

