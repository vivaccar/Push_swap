/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:58:16 by vivaccar          #+#    #+#             */
/*   Updated: 2023/10/19 18:45:20 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	while (i < n && s1[i] == s2[i])
		i++;
	if (n > i)
		return (s1[i] - s2[i]);
	else
		return (0);
}

/* #include <stdio.h>

int	main(void)
{
	char	*str1 = "bom dia";
	char	*str2 = "bom do";
	char	*str3 = "";
	char	*str4 = "";
	char	*str5 = "";
	char	*str6 = "";

	printf("%i\n", ft_memcmp(str1, str2, 5));
} */