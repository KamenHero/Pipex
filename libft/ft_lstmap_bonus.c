/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:01:50 by oryadi            #+#    #+#             */
/*   Updated: 2022/10/30 16:01:51 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*temp;
	t_list	*new;
	void	*data;

	if (!lst || !f || !del)
		return (NULL);
	temp = lst;
	newlst = 0;
	while (temp)
	{
		data = f(temp->content);
		new = ft_lstnew(data);
		if (!new)
		{
			if (data)
				free (data);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, new);
		temp = temp->next;
	}
	return (newlst);
}
