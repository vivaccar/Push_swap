/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinivaccari <vinivaccari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:38:18 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/24 13:02:13 by vinivaccari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_b(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) > 3)
		pb(stack_a, stack_b, 1);
	if (stack_size(*stack_a) > 3)
		pb(stack_a, stack_b, 1);
	while (stack_size(*stack_a) > 3)
	{
		set_datas(stack_a, stack_b);
		push_to_b(stack_a, stack_b);
		pb(stack_a, stack_b, 1);
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
