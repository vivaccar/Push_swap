/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:19:27 by vivaccar          #+#    #+#             */
/*   Updated: 2023/10/29 12:16:51 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);
}

/* #include <stdio.h>

int	main(void)
{
	char	*str;
	t_list	*list;
	
	str = "Vinicius";
	list = ft_lstnew(str);
	printf("%s\n", (char *)list -> next);
	printf("%s", (char *)list -> content);
} */