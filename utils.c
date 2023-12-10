/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:28:39 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/10 18:04:24 by vivaccar         ###   ########.fr       */
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
	while (stack->next)
	{
		if (stack->value > stack->next->value)
		{
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}

t_stack	*find_big(t_stack *stack)
{
	t_stack		*big;
	int			i;

	i = -2147483648;
	big = stack;
	while (stack)
	{
		if (stack->value > i)
		{
			i = stack->value;
			big = stack;
		}
		stack = stack->next;
	}
	return (big);
}

t_stack	*find_last(t_stack *stack)
{
	t_stack	*last;

	while (stack->next)
	{
		stack = stack->next;
	}
	last = stack;
	return (last);
}
void	ft_free(t_stack **head)
{
	t_stack	*to_free;
	t_stack *tmp;

	if(!head)
		return ;
	to_free = *head;
	while (to_free)
	{
		tmp = to_free->next;
		free(to_free);
		to_free = tmp;
	}
	*head = NULL;
}