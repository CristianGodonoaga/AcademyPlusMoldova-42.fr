/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:57:20 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/12 19:22:45 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*ptr_next;
	t_list	*ptr_curent;

	ptr_next = lst->next;
	ptr_curent = lst;
	while (ptr_curent)
	{
		f(ptr_curent);
		ptr_curent = ptr_next;
		ptr_next = ptr_curent->next;
	}
}

