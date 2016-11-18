/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 22:23:54 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/16 22:24:28 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memptr, int value, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		if (*((char*)memptr + i) == ((unsigned char)value))
			return ((void*)(memptr + i));
		i++;
	}
	return (0);
}
