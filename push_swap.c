/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:00:10 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/21 21:07:28 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_datas_b(t_stack **stack_a, t_stack **stack_b)
{
	get_index_med(stack_a);
	get_index_med(stack_b);
	get_target_b(stack_a, stack_b);
}

void	start_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmpa;
	
	tmpa = *stack_a;
	if (stack_size(*stack_a) > 3)
		pb(stack_a, stack_b);
	if (stack_size(*stack_a) > 3)
		pb(stack_a, stack_b);
	while (stack_size(*stack_a) > 3)
	{
		set_datas(stack_a, stack_b);
		push_to_b(stack_a, stack_b);
		pb(stack_a, stack_b);
	//	printf("value pushed: %i\n", (*stack_b)->value);
	}
	set_datas(stack_a, stack_b);
	max_on_top(stack_b);
}

void	push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
	{
		set_datas_b(stack_a, stack_b);
		while (*stack_a != (*stack_b)->target)
		{
			if ((*stack_b)->target->before_med)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pa(stack_a, stack_b);
	}
}

void	min_on_top(t_stack **stack_a)
{
	t_stack	*min;

	min = find_min(*stack_a);
	get_index_med(stack_a);
	while (*stack_a != min)
	{
		if (min->before_med)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	push_swap(t_stack **stack_a)
{
	t_stack		*stack_b;

	stack_b = NULL;
	if (!stack_is_sorted(*stack_a))
	{
		if (stack_size(*stack_a) == 2)
			sa(stack_a);		
		if (stack_size(*stack_a) == 3)
			sort_three(stack_a);
 		if (stack_size(*stack_a) > 3)
			start_b(stack_a, &stack_b);
		sort_three(stack_a);
/* 		t_stack *tmp = stack_b;
		printf ("STACK B COMPLETA:\n");
		if (stack_b)
		{
			set_datas_b(stack_a, &stack_b);
			while (tmp)
			{
			printf("Value: %i, Target: %i, Index: %i, Before: %i, Cost: %i\n", tmp->value, tmp->target->value, tmp->index, tmp->before_med, tmp->cost);
			tmp = tmp->next;	
			}
		} */
		push_to_a(stack_a, &stack_b);
		min_on_top(stack_a);
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
	push_swap(&stack_a);
/* 	t_stack	*test;
	test = stack_a;
	printf ("STACK A:\n");
	while (test)
	{
		printf("Value: %i\n", test->value);
		//printf("Value: %i, Index: %i, Before median: %i, Target: %i, Cost: %i, Cheapest: %i\n", test->value, test-> index, test->before_med, test->target->value, test->cost, test->cheap);
		test = test->next;
	} */
	if (argc == 2)
		str_free(&argv);
	ft_free(&stack_a);
}
