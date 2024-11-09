/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:49:42 by ilbonnev          #+#    #+#             */
/*   Updated: 2024/11/09 16:22:21 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*res;
	void	*elt;

	res = 0;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst != NULL)
	{
		elt = f(lst->content);
		first = ft_lstnew(elt);
		if (first == NULL)
		{
			del(elt);
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, first);
		lst = lst->next;
	}
	return (first);
}
