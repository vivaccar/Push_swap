/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:28:49 by vivaccar          #+#    #+#             */
/*   Updated: 2023/10/29 13:44:24 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/* #include <stdio.h>

int	main(void)
{
	t_list	*lst;
	t_list	*second;
	t_list	*third;

	lst = malloc(sizeof(t_list));
	second = malloc(sizeof(t_list));
	third = malloc(sizeof(t_list));

	lst->content = "1";
	lst->next = second;
	second->content = "2";
	second->next = third;
	third->content = "3";
	third->next = NULL;
	printf("%i", ft_lstsize(lst));
} */