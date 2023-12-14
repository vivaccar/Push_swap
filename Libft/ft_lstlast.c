/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:47:26 by vivaccar          #+#    #+#             */
/*   Updated: 2023/10/29 15:07:46 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/* #include <stdio.h>

int	main(void)
{
	t_list	*lst;

	lst = ft_lstnew("the");
	lst->next = ft_lstnew("last");
	lst->next->next = ft_lstnew("node");
	printf("%s", (char *)ft_lstlast(lst)->content);
}
 */