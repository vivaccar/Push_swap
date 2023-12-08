/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:00:10 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/08 18:51:11 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack		*find_big(t_stack *stack)
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
	printf(1, "%i", 1);
	return (big);
}

void		sort_three(t_stack **head)
{
	
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
	if (!stack_is_sorted(stack_a))
	{
		if (stack_size(stack_a) == 2)
			sa(&stack_a);
		if (stack_size(stack_a) == 3)
			sort_three(&stack_a);
	}
	while (stack_a != NULL)
	{
		printf("\n%i", stack_a->value);
		stack_a = stack_a->next;
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