/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 13:34:45 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/12/28 13:38:12 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Delete the list and free content with function free()
*/

#include "libft.h"

void		ft_lstfree(t_list **pT_head)
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