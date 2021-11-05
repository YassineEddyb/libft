/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:59:05 by yed-dyb           #+#    #+#             */
/*   Updated: 2021/11/05 14:31:43 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *lst;
	while (tmp1)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	tmp2->next = new;
}

/*int main () {
	t_list *head;
	head = malloc(3 * sizeof(t_list));
	head->content = "first";
	head->next = ft_lstnew("second");
	head->next->next = ft_lstnew("third");
	head->next->next->next = NULL;

	ft_lstadd_back(&head, ft_lstnew("fourth"));
	while (head) {
		printf("%s\n", head->content);
		head = head->next;
	}
}*/
