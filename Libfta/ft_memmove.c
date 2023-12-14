/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:01:54 by vivaccar          #+#    #+#             */
/*   Updated: 2023/10/19 17:19:49 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_char;
	const unsigned char	*src_char;

	if (dest == NULL && src == NULL)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	src_char = (unsigned char *)src;
	dest_char = (unsigned char *)dest;
	while (n--)
		dest_char[n] = src_char[n];
	return (dest);
}

/*#include <stdio.h>
int	main(void)
{
	char	src[] = "Vinicius";
	char	dest[3];
	
	printf("dest antes: %s\n", dest);
	printf("dest depois: %s", (char *)ft_memmove(dest, src, 4));
}*/