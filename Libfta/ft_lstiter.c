/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:02:58 by vivaccar          #+#    #+#             */
/*   Updated: 2023/10/30 12:51:59 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/* #include <stdio.h> 

void	ft_iter(void *content)
{
	printf("%s\n", (char *)content);
}

int main(void)
{
	t_list	*lst;

	lst = ft_lstnew("hi");
	lst->next = ft_lstnew("hola");
	lst->next->next = ft_lstnew("ola");
	printf("%s\n", (char *)lst->content);
	ft_lstiter(lst, (void *)&ft_iter);
} */