/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:44:47 by oryadi            #+#    #+#             */
/*   Updated: 2022/10/30 15:44:48 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*tmpnxt;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		tmpnxt = temp->next;
		ft_lstdelone(temp, del);
		temp = tmpnxt;
	}
	*lst = NULL;
}
