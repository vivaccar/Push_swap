/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:00:10 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/12 22:22:21 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_sort(t_stack **stack_a)
{
	if (!stack_is_sorted(*stack_a))
	{
		if (stack_size(*stack_a) == 2)
			sa(stack_a);		
		else if (stack_size(*stack_a) >= 3)
			sort_three(stack_a);
	}
}

int	main(int argc, char	**argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc == 1 || (!argv[1][0] && argc == 2))
		return (0);
	if (!check_input(argv, argc))
		return (write (2, "Error", 5));
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else 
		argv = argv + 1;
	start_stack(&stack_a, argv);
	stack_sort(&stack_a);
	if (argc == 2)
		str_free(&argv);
	ft_free(&stack_a);
}
/* 	
	t_stack	*test
	test = stack_a;
	while (test)
	{
		printf("%i\n", test->value);
		test = test->next;
	} */