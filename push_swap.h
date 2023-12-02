/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:19:34 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/02 17:24:50 by vivaccar         ###   ########.fr       */
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
	//struct s_stack	*prev;
}					t_stack;

// CHECK ERRORS
int			check_input(char **argv, int argc);
int			check_digit(char *number);
int			check_repeat(char **numbers, int t);

// START STACK
t_stack		*create_node(int n);
void		start_stack(t_stack **head, char **argv);

#endif