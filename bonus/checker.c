/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:56:23 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/28 10:57:09 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char	**argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc == 1 || (!argv[1][0] && argc == 2))
		return (0);
	check_input(argc, argv);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else 
		argv = argv + 1;
	start_stack(&stack_a, argv);
	if (argc == 2)
		str_free(&argv);
	read_commands(&stack_a);
}
