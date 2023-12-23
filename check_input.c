/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinivaccari <vinivaccari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:27:33 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/23 22:26:25 by vinivaccari      ###   ########.fr       */
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

void	check_input(int argc, char **argv)
{
	int			i;
	long long	t;
	
	i = 0;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = argv + 1;
	while (argv[i])
	{
		t = ft_atol(argv[i]);
		if ((t > INT_MAX || t < INT_MIN) || !argv[i][0]
			|| !check_digit(argv[i]) || !check_repeat(argv, t))
		{
			if (argc == 2)
				str_free(&argv);
			write (1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	if (argc == 2)
		str_free(&argv);
}

