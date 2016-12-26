/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:59:06 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/21 16:27:46 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*temp;

	temp = (t_list*)malloc(sizeof(*temp));
	if (!temp)
		return (NULL);
	temp->next = NULL;
	if (!content)
	{
		temp->content = NULL;
		temp->content_size = 0;
	}
	else
	{
		temp->content = (void*)malloc(content_size);
		ft_memcpy(temp->content, content, content_size);
		temp->content_size = content_size;
	}
	return (temp);
}
