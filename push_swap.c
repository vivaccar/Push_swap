/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:00:10 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/20 21:09:56 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	max_on_top(t_stack **stack)
{
	t_stack		*big;

	big = find_big(*stack);
	t_stack *tmp = *stack;
	//printf ("STACK B ANTES DE COLOCAR O MAIOR NO TOPO:\n");
	//printf ("Big: %i\n", big->value);
	while (tmp)
	{
		//printf("Value: %i, Index: %i, Before median: %i\n", tmp->value, tmp-> index, tmp->before_med);
		tmp = tmp->next;	
	}
	while (*stack != big)
	{
		if (big->before_med)
			rb(stack);
		else
			rrb(stack);
	}
}

t_stack	*find_min(t_stack *stack)
{
	int	i;
	t_stack	*min;
	
	i = INT_MAX;
	while (stack)
	{
		if (stack->value < i)
		{
			i = stack->value;
			min = stack;
		}
		stack = stack->next;
	}
	printf("Minimo: %i",min->value);
	return (min);
}

void	get_target_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*cur_a;
	int		cur_match;
	
	tmp = *stack_b;
	while (tmp)
	{
		cur_match = INT_MAX;
		cur_a = *stack_a;
		while (cur_a)
		{
			if(cur_a->value < cur_match && tmp->value > cur_a->value)
			{
				tmp->target = cur_a;
				cur_match = cur_a->value;
			}
			cur_a = cur_a->next;
		}	
		if(cur_match == INT_MAX)
			tmp->target = find_min(*stack_a);
		tmp = tmp->next;
	}
}

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
	t_stack *tmp = *stack_b;
	printf ("STACK B COMPLETA:\n");
	while (tmp)
	{
		printf("Value: %i, Index: %i, Before median: %i, Target: %i\n", tmp->value, tmp-> index, tmp->before_med, tmp->target->value);
		tmp = tmp->next;	
	}
	if (*stack_b)
	{
		set_datas_b(stack_a, stack_a);
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
	t_stack	*test;
	test = stack_a;
	printf ("STACK A:\n");
	while (test)
	{
		printf("Value: %i\n", test->value);
		//printf("Value: %i, Index: %i, Before median: %i, Target: %i, Cost: %i, Cheapest: %i\n", test->value, test-> index, test->before_med, test->target->value, test->cost, test->cheap);
		test = test->next;
	}
	if (argc == 2)
		str_free(&argv);
	ft_free(&stack_a);
}
