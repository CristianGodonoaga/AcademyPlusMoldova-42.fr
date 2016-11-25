/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 18:30:24 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/25 14:00:36 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *memptr, int value, size_t num)
{
	size_t		i;
	const char	*temp;

	temp = (const char*)memptr;
	i = 0;
	while (i < num)
	{
		if ((unsigned char)temp[i] == ((unsigned char)value))
			return ((void*)(temp + i));
		i++;
	}
	return (0);
}
