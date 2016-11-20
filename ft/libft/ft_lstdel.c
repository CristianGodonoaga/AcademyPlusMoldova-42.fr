/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:53:00 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/12 20:16:40 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr_next;
	t_list	*ptr_curent;
	
	if (!alst || !del)
		return ;
	ptr_next = (*alst)->next;
	ptr_curent = *alst;
	while (ptr_curent)
	{
		del(ptr_curent->content, ptr_curent->content_size);
		free(ptr_curent);
		ptr_curent = ptr_next;
		ptr_next = ptr_curent->next;
	}
	*alst = NULL;
}
