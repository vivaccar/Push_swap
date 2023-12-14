/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:17:53 by vivaccar          #+#    #+#             */
/*   Updated: 2023/10/28 17:15:07 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		(*f)(i, (s + i));
		++i;
	}
}
/* #include <stdio.h>

void	ft_test(unsigned int i, char *str)
	{
		*str += i;
	}

int	main()
{
	char	str[] = "HELLO";
	ft_striteri(str, ft_test);
	printf("%s", str);
} */