/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:00:10 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/03 17:51:17 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = *head;
	temp2 = (*head)->next;
	temp1->next = temp2->next;
	temp2->next->prev = temp1;
	temp1->prev = temp2;

	*head = temp2;
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
	last_node(stack_a);
	if (!stack_is_sorted(stack_a))
	if (stack_size(stack_a) == 2)
		swap(&stack_a);
	while (stack_a != NULL)
	{
		printf("%i", stack_a->value);
		stack_a = stack_a->next;
		printf("\n");
	}
	//return (write (1, "ok", 2));

}
/* 	while (stack_a != NULL)
	{
		printf("%i", stack_a->value);
		stack_a = stack_a->next;
		printf("\n");
	} */

	//printf("%i", stack_a->prev->value);