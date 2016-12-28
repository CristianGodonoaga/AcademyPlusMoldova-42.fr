/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 18:02:20 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/12/28 18:02:23 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **pT_head)
{
	t_list	*ptr_next;

	while (*pT_head)
	{
		ptr_next = (*pT_head)->next;
		free((*pT_head)->content);
		free(*pT_head);
		*pT_head = ptr_next;
	}
	*pT_head = NULL;
}
