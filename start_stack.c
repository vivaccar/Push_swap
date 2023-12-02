/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:38:18 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/02 17:15:20 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int n)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node ->value = n;
	node ->next = NULL;
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
		}
		i++;
	}
}