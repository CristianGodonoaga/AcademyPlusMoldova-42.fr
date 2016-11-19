/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:59:06 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/18 23:03:18 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*temp;

	temp = (t_list*)malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
	temp->content = (void*)content;
	temp->next = NULL;
	if (!content)
		temp->content_size = 0;
	else
		temp->content_size = content_size;
	return (temp);
}
