/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 18:28:27 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/20 18:28:33 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *temp;

	if (!lst || !f)
		return (NULL);
	result = f(lst);
	temp = result;
	while (lst->next)
	{
		lst = lst->next;
		if (!temp)
			return (NULL);
		temp->next = f(lst);
		temp = temp->next;
	}
	return (result);
}
