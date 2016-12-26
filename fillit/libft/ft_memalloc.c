/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:01:22 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/19 18:49:15 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*temp;

	if (size < 1)
		return (NULL);
	temp = (char*)malloc(sizeof(temp) * size);
	if (!temp)
		return (NULL);
	while (size-- > 0)
		*(temp + size) = 0;
	return ((void *)temp);
}
