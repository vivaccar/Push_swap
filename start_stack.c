/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:38:18 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/23 16:32:03 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_b(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) > 3)
		pb(stack_a, stack_b);
	if (stack_size(*stack_a) > 3)
		pb(stack_a, stack_b);
	while (stack_size(*stack_a) > 3)
	{
		set_datas(stack_a, stack_b);
		push_to_b(stack_a, stack_b);
		pb(stack_a, stack_b);
	}
	set_datas(stack_a, stack_b);
	max_on_top(stack_b);
}

t_stack	*create_node(int n)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->value = n;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	start_stack(t_stack **head, char **argv)
{
	int		i;
	t_stack	*new_last;
	t_stack	*temp;

	i = 0;
	while (argv[i])
	{
		new_last = create_node(ft_atoi(argv[i]));
		if (*head == NULL)
			*head = new_last;
		else
		{
			temp = *head;
			while (temp ->next != NULL)
				temp = temp->next;
			temp ->next = new_last;
			new_last ->prev = temp;
		}
		i++;
	}
}
