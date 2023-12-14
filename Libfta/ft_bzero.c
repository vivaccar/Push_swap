/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:02:52 by vivaccar          #+#    #+#             */
/*   Updated: 2023/10/19 12:34:49 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char		*p;
	size_t		i;

	p = (char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

/*#include <stdio.h>

int	main(void)
{
	char	string[] = "Vinicius";
	size_t	size;

	size = ft_strlen(string);
	printf("antes: %s\n", string);
	ft_bzero(string, size);
	printf("depois: %s", string);
}*/