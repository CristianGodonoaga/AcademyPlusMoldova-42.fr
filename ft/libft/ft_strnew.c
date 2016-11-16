/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 20:01:52 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/12 20:02:23 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*temp;

	if (size < 1)
		return (NULL);
	temp = (char*)malloc(sizeof(temp) * size + 1);
	if (!temp)
		return (NULL);
	while ((size--)>0)
		*(temp + size) = '\0';
	return temp;
}