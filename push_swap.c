/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:00:10 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/17 06:02:19 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_target(t_stack **a, t_stack **b)
{
	t_stack		*tmp;
	t_stack		*cur_b;
	int			cur_match;

	tmp = *a;
	while (tmp)
	{
		cur_match = INT_MIN;
		cur_b = *b;
		while (cur_b)
		{
			if (cur_b->value > cur_match && cur_b->value < tmp->value)
			{
				tmp->target = cur_b;
				cur_match = cur_b->value;
			}
			cur_b = cur_b->next;
		}
		if (cur_match == INT_MIN)
			tmp->target = find_big(*b);
		tmp = tmp->next;
	}
}

void	get_index_med(t_stack **a)
{
	int		size;
	int		i;
	t_stack	*tmp;
	
	size = stack_size(*a);
	tmp = *a;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		if (size / 2 > i)
			tmp->before_med = 1;
		else
			tmp->before_med = 0;
		tmp = tmp->next;
		i++;
	}
}

void	get_cost(t_stack **a, t_stack **b)
{
	int	size_a;
	int	size_b;
	t_stack *tmp;

	size_a = stack_size(*a);
	size_b = stack_size(*b);
	tmp = *a;
	while (tmp)
	{
		if (!(tmp->before_med) && !(tmp->target->before_med))
		{
			if (tmp->index >= tmp->target->index)
				tmp->cost = size_b - tmp->target->index;
			else
				tmp->cost = size_a - tmp->index;
		}
		else if (tmp->before_med && tmp->target->before_med)
		{
			if (tmp->index >= tmp->target->index)
				tmp->cost = tmp->index;
			else
				tmp->cost = tmp->target->index;
		}
		else
		{
			if ((tmp->before_med) && !(tmp->target->before_med))
				tmp->cost = (size_b - tmp->target->index) + tmp->index;
			else 
				tmp->cost = (size_a - tmp->index) + tmp->target->index;			
		}
		tmp = tmp->next;
	}
}


void	set_cheapest(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*cheap_node;
	int		cur_cheapest;
	
	tmp = *a;
	cheap_node = *a;
	cur_cheapest = INT_MAX;
	while (tmp)
	{
		if (tmp->cost < cur_cheapest)
		{
			cheap_node = tmp;
			cur_cheapest = tmp->cost;	
		}
		tmp = tmp->next;
	}
	tmp = *a;
	cheap_node->cheap = 1;
	while (tmp)
	{
		if (tmp != cheap_node)
			tmp->cheap = 0;
		tmp = tmp->next;
	}
}

void	set_datas(t_stack **a, t_stack **b)
{
	get_index_med(a);
	get_index_med(b);
	get_target(a, b);
	get_cost(a, b);
	set_cheapest(a);
}

t_stack	*get_cheapest(t_stack *a)
{
	t_stack	*tmp;
	
	tmp = a;
	while (tmp)
	{
		if (tmp->cheap == 1)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

t_stack	*start_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (stack_size(*stack_a) > 3)
		pb(stack_a, &stack_b);
	if (stack_size(*stack_a) > 3)
		pb(stack_a, &stack_b);
	set_datas(stack_a, &stack_b);
	t_stack *tmp = stack_b;
	printf ("STACK B:\n");
	while (tmp)
	{
		printf("Value: %i, Index: %i, Before median: %i\n", tmp->value, tmp-> index, tmp->before_med);
		tmp = tmp->next;	
	}
	return (stack_b);	
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
			stack_b = start_b(stack_a);
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
		printf("Value: %i, Index: %i, Before median: %i, Target: %i, Cost: %i, Cheapest: %i\n", test->value, test-> index, test->before_med, test->target->value, test->cost, test->cheap);
		test = test->next;
	}
	if (argc == 2)
		str_free(&argv);
	ft_free(&stack_a);
}