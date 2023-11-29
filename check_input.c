/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:27:33 by vivaccar          #+#    #+#             */
/*   Updated: 2023/11/29 16:03:27 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_repeat(char **numbers, int t, int j)
{
	int	i;
	int	c;

	c = 0;
	i = j;
	while (numbers[j])
	{
		if (ft_atoi(numbers[j]) == t)
		{
			c++;
			if (c == 2)
				return (0);
		}
		j++;
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
	int		j;
	
	i = 0;
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
	{
		numbers = argv;
		i = 1;
		j = 1;
	}
	while (numbers[i])
	{
		t = ft_atoi(numbers[i]);
		if (!check_digit(numbers[i]) || !check_repeat(numbers, t , j))
			return (0);
		i++;
	}
	free (numbers);
	return (1);
}

