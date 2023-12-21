/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:27:33 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/21 21:01:29 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atol(const char *str)
{
	int			i;
	long long	result;
	long long	signal;

	signal = 1;
	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if ((str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			signal = signal * -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * signal);
}

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
			return (0);
		i++;
	}
	return (1);
}


void	str_free(char ***numbers)
{
	int	i;

	i = 0;
	while ((*numbers)[i])
	{
		free((*numbers)[i]);
		(*numbers)[i] = NULL;
		i++;
	}
	free(*numbers);
	*numbers = NULL;
}

int	check_input(char **argv, int argc)
{
	char			**numbers;
	int				i;
	long long		t;

	i = 0;
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
		numbers = argv + 1;
	while (numbers[i])
	{
		t = ft_atol(numbers[i]);
		if ((t > INT_MAX || t < INT_MIN) || !numbers[i][0]
			|| !check_digit(numbers[i]) || !check_repeat(numbers, t))		
		{
			if (argc == 2)
				str_free(&numbers);
			return (0);
		}
		i++;
	}
	if (argc == 2)
		str_free(&numbers);
	return (1);
}
