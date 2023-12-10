/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:00:10 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/10 18:04:17 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char	**argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*test;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || !argv[1][0])
		return (0);
	if (!check_input(argv, argc))
		return (write (1, "Error", 5));
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else 
	argv = argv + 1;
	start_stack(&stack_a, argv);
	if (!stack_is_sorted(stack_a))
	{
		if (stack_size(stack_a) == 2)
			sa(&stack_a);
		else if (stack_size(stack_a) >= 3)
			sort_three(&stack_a);
	}
	test = stack_a;
	while (test)
	{
		printf("%i\n", test->value);
		test = test->next;
	}
	ft_free(&stack_a);
	//return (write (1, "ok", 2));

}
/* 	while (stack_a != NULL)
	{
		printf("%i", stack_a->value);
		stack_a = stack_a->next;
		printf("\n");
	} */

	//printf("%i", stack_a->prev->value);