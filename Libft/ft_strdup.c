/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:30:50 by vivaccar          #+#    #+#             */
/*   Updated: 2023/10/20 15:41:33 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(str) + 1;
	dup = malloc(size);
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, str, size);
	return (dup);
}

/* #include <stdio.h>

int	main(void)
{
	char	*src;
	char	*dup;

	src = "Vinicius";
	dup = "";

	printf("antes: %s", dup);
	dup = ft_strdup(src);
	printf("depois: %s", dup);
} */