/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinivaccari <vinivaccari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:19:34 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/27 22:38:03 by vinivaccari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "stdlib.h"
# include "unistd.h"
# include "stdio.h"
# include "limits.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				before_med;
	int				cost;
	int				cheap;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}					t_stack;

// CHECK ERRORS
void		check_input(int argc, char **argv);
int			check_digit(char *number);
int			check_repeat(char **numbers, int t);
long long	ft_atol(const char *str);
void		str_free(char ***numbers);

// START STACK
t_stack		*create_node(int n);
void		start_stack(t_stack **head, char **argv);
void		start_b(t_stack **stack_a, t_stack **stack_b);

// UTILS SORT
int			stack_is_sorted(t_stack *stack);
int			stack_size(t_stack *stack);
t_stack		*find_big(t_stack *stack);
t_stack		*find_last(t_stack *stack);
void		ft_free(t_stack **head);
t_stack		*find_min(t_stack *stack);
void		min_on_top(t_stack **stack_a);
void		max_on_top(t_stack **stack);

// SET DATAS
void		set_datas(t_stack **a, t_stack **b);
void		get_target(t_stack **a, t_stack **b);
void		get_cost(t_stack **a, t_stack **b);
void		check_decrease_cost(t_stack *tmp, t_stack **a, t_stack **b);
t_stack		*set_cheapest(t_stack **a);
void		get_index_med(t_stack **a);

// SORTS
void		sort_three(t_stack **head);
void		push_swap(t_stack **stack_a);

// ROTATE
void		rotate(t_stack **head);
void		ra(t_stack **stack_a, int flag);
void		rb(t_stack	**stack_b, int flag);
void		rr(t_stack **stack_a, t_stack **stack_b, int flag);

// SWAP
void		swap(t_stack **head);
void		sa(t_stack **a, int flag);
void		sb(t_stack **b, int flag);
void		ss(t_stack **a, t_stack **b, int flag);

// REV ROTATE
void		r_rotate(t_stack **head);
void		rra(t_stack **a, int flag);
void		rrb(t_stack **b, int flag);
void		rrr(t_stack **a, t_stack **b, int flag);

// PUSH
void		pa(t_stack **a, t_stack **b, int flag);
void		pb(t_stack **a, t_stack **b, int flag);
void		push(t_stack **out, t_stack **in);

// PUSH B
void		rotate_ab(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node);
void		rev_rotate_ab(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node);
void		ra_and_rrb(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node);
void		rra_and_rb(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node);
void		push_to_b(t_stack **stack_a, t_stack **stack_b);

// PUSH A
void		get_target_b(t_stack **stack_a, t_stack **stack_b);
void		push_to_a(t_stack **stack_a, t_stack **stack_b);
void		set_datas_b(t_stack **stack_a, t_stack **stack_b);

#endif