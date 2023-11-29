/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:00:10 by vivaccar          #+#    #+#             */
/*   Updated: 2023/11/29 16:35:29 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**start_values(int argc, char **argv)
{
	char	**values;
	
	if (argc == 2)
	{
		values == ft_split(argv, ' ');
		return (values);
	}
	else
	return (argv);
}
t_stack	*start_stack(char **values, int argc)
{
	t_stack	*stack_a;
	int		i;
	int		number;
	
	i = 1;
	number = 0;
	stack_a = NULL;
	
	while (values[i])
	{
		number = ft_atoi(values[i]);
		stack_a = ft_lstnew((void *)number);
	}
	
}

int	main(int argc, char	**argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**values;
	
	if (!check_input(argv, argc))
		return(write (1, "erro", 4));
	return (write (1, "ok", 2));
	stack_a = malloc(sizeof(t_stack));
	stack_b = NULL;
	values = start_values(argc, argv);
	stack_a = start_stack(values, argc);
}
