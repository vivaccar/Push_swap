/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:18:47 by vivaccar          #+#    #+#             */
/*   Updated: 2023/10/29 18:24:53 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*next;

	ptr = *lst;
	while (ptr)
	{
		next = ptr->next;
		del(ptr->content);
		free(ptr);
		ptr = next;
	}
	*lst = NULL;
}

/*  
void ft_delete(void *list)
{
	list = NULL;
}

#include <stdio.h>

int main(void)
{
	t_list	*list;

	list = ft_lstnew("1st");
	list->next = ft_lstnew("2nd");
	list->next->next = ft_lstnew("3rd");
	printf("%s\n", (char *)list->content);
	ft_lstclear(&list, ft_delete);
	printf("%s\n", (char *)list);
} */