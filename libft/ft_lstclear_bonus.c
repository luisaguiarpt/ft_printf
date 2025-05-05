/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:27:54 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/15 13:47:40 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		if ((*lst)->content)
			ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	free(*lst);
	*lst = NULL;
}
/*
#include <stdio.h>

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("\n");
}

void	delete_ls(void *addr)
{
	free(addr);
}

int	main(void)
{
	t_list	*lst;
	t_list	**ptr;
	t_list	**ptr2;

	ptr = &lst;
	ptr2 = &lst;
	lst = ft_lstnew((void *)ft_strdup("1"));
	lst->next = ft_lstnew((void *)ft_strdup("2"));
	lst->next->next = ft_lstnew((void *)ft_strdup("3"));

	printf("Before: \n");
	print_list(*ptr);
	ft_lstclear(&lst, delete_ls);
	printf("After: \n");
	print_list(*ptr2);
}
*/
