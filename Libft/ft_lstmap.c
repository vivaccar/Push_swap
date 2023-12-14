/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:21:14 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/08 15:57:38 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*result;
	void	*content;

	result = NULL;
	while (lst)
	{
		content = f(lst->content);
		new = ft_lstnew(content);
		if (!new)
		{
			del(content);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, new);
		lst = lst->next;
	}
	return (result);
}

/* #include <stdio.h>

void ft_del(void *lst)
{
    if (lst)
    {
        free(lst);
    }
}
void ft_iter(void *ptr)
{
	//static int i;
	
	//printf("%d\n", i);
	//i++;
    char *s = (char *)ptr;
    s = "Hello World";

	//(char *)ptr = "hsahas";
	//return(ptr);
}


int main(void)
{
    t_list *lista;

    lista = ft_lstnew("1st");
    lista->next = ft_lstnew("2nd");
    lista->next->next = ft_lstnew("3rd");

    printf("Original:\n");
    printf("%s\n", (char *)lista->content);

    lista = ft_lstmap(lista, (void *)&ft_iter, (void *)&ft_del);

    printf("Modificado:\n");
    printf("%s\n", (char *)lista->content);
}
 */
