/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:31:31 by vivaccar          #+#    #+#             */
/*   Updated: 2023/10/29 18:15:04 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

/* void ft_delete(void *list)
{
	t_list	*a;

	a = (t_list *)list;
	a->content = NULL;
}
#include<stdio.h>

int main(void)
{
	t_list *list;

	list = ft_lstnew("conteudo que vai ser apagado");
	printf("%s\n", (char *)list->content);
	ft_lstdelone(list, ft_delete);
	printf("%s\n", (char *)list->content);
} */