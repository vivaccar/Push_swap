/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:08:30 by vivaccar          #+#    #+#             */
/*   Updated: 2023/10/29 16:37:20 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	back = *lst;
	while (back->next)
		back = back->next;
	back->next = new;
}

/* #include <stdio.h>

int	main(void)
{
	t_list	*last;
	t_list	*lst;
	t_list	*new;

	lst = ft_lstnew("one");
	lst->next = ft_lstnew("two");
	lst->next->next = ft_lstnew("three");
	last = ft_lstlast(lst);
	printf("O ultimo conteudo: %s\n", (char *)last->content);
	ft_lstadd_back(&lst, ft_lstnew("four"));
	last = ft_lstlast(lst);
	printf("O ultimo conteudo depois: %s\n", (char *)last->content);
} */