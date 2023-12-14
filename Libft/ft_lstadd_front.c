/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:59:08 by vivaccar          #+#    #+#             */
/*   Updated: 2023/10/29 16:37:26 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/* #include <stdio.h>

int	main(void)
{
	t_list	*lst;
	t_list	*new;
	
	lst = ft_lstnew("1");
	lst->next = ft_lstnew("2");
	lst->next->next = ft_lstnew("3");
	printf("O primeiro conteudo da lista: %s\n", (char *)lst->content);
	ft_lstadd_front(&lst, ft_lstnew("0"));
	printf("Agora mudou para: %s", (char *)lst->content);
} */