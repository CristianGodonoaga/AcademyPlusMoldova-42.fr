/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrevers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 01:31:01 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/12/27 01:38:22 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstrevers(t_list **pToHead)
{
	t_list	*preview;
	t_list	*current;
	t_list	*next;

	if (!pToHead)
		return ;
	current = *pToHead;
	preview = NULL;
	while (current)
	{
		next = current->next;
		current->next = preview;
		preview = current;
		current = next;
	}
	*pToHead = preview;
}
