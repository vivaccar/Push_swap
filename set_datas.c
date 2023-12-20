/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_datas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:30:21 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/20 19:16:11 by vivaccar         ###   ########.fr       */
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

t_stack	*set_cheapest(t_stack **a)
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
	return (cheap_node);
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
		tmp->cost = tmp->index;
		if (!tmp->before_med)
			tmp->cost = size_a - tmp->index;
		if (tmp->target->before_med)
			tmp->cost += tmp->target->index;
		else
			tmp->cost += size_b - (tmp->target->index);
		tmp = tmp->next;
	}
}

void	set_datas(t_stack **a, t_stack **b)
{
	get_index_med(a);
	get_index_med(b);
	get_target(a, b);
	get_cost(a, b);
}