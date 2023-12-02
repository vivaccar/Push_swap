/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:00:10 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/02 17:15:38 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char	**argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
 	if (argc == 1 || !argv[1][0])
		return (0);
	if (!check_input(argv, argc))
		return(write (1, "erro", 4));
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else 
		argv = argv + 1;
	start_stack(&stack_a, argv);
	while (stack_a != NULL)
	{
		printf("%i", stack_a->value);
		stack_a = stack_a->next;
		printf("\n");
	}
	return (write (1, "ok", 2));
}
