/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:00:10 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/02 17:12:34 by vivaccar         ###   ########.fr       */
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

int	main(int argc, char	**argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
 	if (argc == 1 || !argv[1][0])
		return (0);
	if (!check_input(argv, argc))
		return(write (1, "erro", 4));
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else 
		argv = argv + 1;
	start_stack(&stack_a, argv);
	while (stack_a != NULL)
	{
		printf("%i", stack_a->value);
		stack_a = stack_a->next;
		printf("\n");
	}
	//return (write (1, "ok", 2));
}
