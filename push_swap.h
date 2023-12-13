/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:19:34 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/13 21:58:06 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include "stdlib.h"
# include "unistd.h"
# include "stdio.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// CHECK ERRORS
int			check_input(char **argv, int argc);
int			check_digit(char *number);
int			check_repeat(char **numbers, int t);

// START STACK
t_stack		*create_node(int n);
void		start_stack(t_stack **head, char **argv);
long long	ft_atol(const char *str);

// UTILS SORT
int			stack_is_sorted(t_stack *stack);
int			stack_size(t_stack *stack);
t_stack		*find_big(t_stack *stack);
void		sort_three(t_stack **head);
t_stack		*find_last(t_stack *stack);
void		ft_free(t_stack **head);
void		str_free(char ***numbers);
void		stack_sort(t_stack **stack_a);

// ROTATE
void		rotate(t_stack **head);
void		ra(t_stack **stack_a);

// SWAP
void		swap(t_stack **head);
void		sa(t_stack **a);

// REV ROTATE
void		r_rotate(t_stack **head);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

// PUSH
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		push(t_stack **out, t_stack **in);

#endif