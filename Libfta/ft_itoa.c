/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:39:17 by vinivaccari       #+#    #+#             */
/*   Updated: 2023/10/26 13:27:34 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	int_len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	size;
	char			*str;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = int_len(n);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (str)
	{
		str[size] = '\0';
		if (n < 0)
		{
			str[0] = '-';
			n = -n;
		}
		while (n)
		{
			str[--size] = '0' + (n % 10);
			n /= 10;
		}
	}
	return (str);
}

/* #include <stdio.h>

int main(void)
{
    printf("%s", ft_itoa(0));
} */