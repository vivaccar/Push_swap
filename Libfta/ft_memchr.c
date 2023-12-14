/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:22:59 by vivaccar          #+#    #+#             */
/*   Updated: 2023/10/19 17:57:38 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;
	size_t			i;

	c = (unsigned char)c;
	i = 0;
	s = (unsigned char *)str;
	while (i < n)
	{
		if (s[i] == c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}

/* #include <stdio.h>

int	main(void)
{
	char	str[] = "procurando a letra";
	char	c = 'c';

	printf("%s", (char *)ft_memchr(str, c, ft_strlen(str)));
} */