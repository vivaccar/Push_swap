/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:27:33 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/02 17:21:53 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_repeat(char **numbers, int t)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (numbers[i])
	{
		if (ft_atoi(numbers[i]) == t)
		{
			c++;
			if (c == 2)
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_digit(char *number)
{
	int	i;

	i = 0;
	if (number[0] == '-')
		i++;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return(0);
		i++;
	}
	return(1);
}

int	check_input(char **argv, int argc)
{
	char	**numbers;
	int		i;
	int		t;

	i = 0;
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
	{
		numbers = argv + 1;
	}
	while (numbers[i])
	{
		t = ft_atoi(numbers[i]);
		if (!check_digit(numbers[i]) || !check_repeat(numbers, t))
			return (0);
		i++;
	}
	if (argc == 2)
		free (numbers);
	return (1);
}

