/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:35:37 by vivaccar          #+#    #+#             */
/*   Updated: 2023/10/19 14:00:51 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_char;
	const char	*src_char;

	i = 0;
	if (n == 0)
		return (dest);
	if (dest == NULL && src == NULL)
		return (NULL);
	dest_char = (char *)dest;
	src_char = (const char *)src;
	while (i < n)
	{
		dest_char[i] = src_char[i];
		i++;
	}
	return (dest);
}

/*#include <stdio.h>
int	main(void)
{
	char	src[] = "Vinicius";
	char	dest[8];
	
	printf("dest antes: %s\n", dest);
	printf("dest depois: %s", (char *)ft_memcpy(dest, src, 9));
}*/