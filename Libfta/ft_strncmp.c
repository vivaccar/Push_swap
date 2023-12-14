/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:22:40 by vivaccar          #+#    #+#             */
/*   Updated: 2023/10/18 15:47:15 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((s1[i]) || (s2[i])) && (i < n))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	a[] = "abcde";
	char	b[] = "abcdefg";
	char	c[] = "hellofriend";
	char	d[] = "helloworld";
	char	e[] = "123456";
	char	f[] = "1098";

	printf("%i\n", ft_strncmp(a, b, 6));
	printf("%i\n", strncmp(a, b, 6));
	printf("%i\n", ft_strncmp(c, d, 5));
	printf("%i\n", strncmp(c, d, 5));
	printf("%i\n", ft_strncmp(e, f, 4));
	printf("%i\n", strncmp(e, f, 4));

}*/