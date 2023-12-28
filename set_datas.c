/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_datas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:30:21 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/28 10:45:50 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	check_decrease_cost(t_stack *tmp, t_stack **a, t_stack **b)
{
	if (tmp->before_med && tmp->target->before_med)
	{
		if (tmp->index < tmp->target->index)
			tmp->cost -= tmp->index;
		else
			tmp->cost -= tmp->target->index;
	}
	if (!(tmp->before_med) && !(tmp->target->before_med))
	{
		if (stack_size(*a) - tmp->index < stack_size(*b) - tmp->target->index)
			tmp->cost -= stack_size(*a) - tmp->index;
		else
			tmp->cost -= stack_size(*b) - tmp->target->index;
	}
}

void	get_cost(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->before_med)
			tmp->cost = tmp->index;
		if (!tmp->before_med)
			tmp->cost = stack_size(*a) - tmp->index;
		if (tmp->target->before_med)
			tmp->cost += tmp->target->index;
		if (!(tmp->target->before_med))
			tmp->cost += stack_size(*b) - tmp->target->index;
		check_decrease_cost(tmp, a, b);
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
