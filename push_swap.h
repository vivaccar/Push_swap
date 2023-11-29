/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:19:34 by vivaccar          #+#    #+#             */
/*   Updated: 2023/11/29 16:24:30 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
 
# include "../Libft/libft.h"
# include "stdlib.h"
# include "unistd.h"

typedef struct s_stack
{
	int				*value;
	struct s_stack	*next;
	//struct s_stack	*prev;
}					t_stack;

// CHECK ERRORS
int		check_input(char **argv, int argc);
int		check_digit(char *number);
int		check_repeat(char **numbers, int t, int j);

#endif