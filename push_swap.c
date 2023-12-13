/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:00:10 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/13 22:03:17 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **out, t_stack **in)
{
	t_stack	*tmp;

	if (!*out)
		return ;
	tmp = *in;
	*in = *out;
	*out = (*out)->next;
	(*in)->next = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write (1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write (1, "pb\n", 3);
}

void	stack_sort(t_stack **stack_a)
{
	t_stack	*stack_b = NULL;

	if (!stack_is_sorted(*stack_a))
	{
		if (stack_size(*stack_a) == 2)
			sa(stack_a);		
		if (stack_size(*stack_a) == 3)
			sort_three(stack_a);
		if (stack_size(*stack_a) > 3)
			pb(stack_a, &stack_b);
		if (stack_size(*stack_a) > 3)
			pb(stack_a, &stack_b);
		//rrb(&stack_b);
		t_stack *tmp = stack_b;
		printf ("STACK B:\n");
		while (tmp)
		{
			printf("%i\n", tmp->value);
			tmp = tmp->next;
		}		
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
	t_stack	*test;
	test = stack_a;
	printf ("STACK A:\n");
	while (test)
	{
		printf("%i\n", test->value);
		test = test->next;
	}
	if (argc == 2)
		str_free(&argv);
	ft_free(&stack_a);
}