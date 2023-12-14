/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:06:39 by vivaccar          #+#    #+#             */
/*   Updated: 2023/10/20 14:30:41 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_elem, size_t size)
{
	void	*ptr;

	ptr = malloc(n_elem * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, size * n_elem);
	return (ptr);
}
