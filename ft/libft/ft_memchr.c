/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:03:47 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/12 19:25:08 by cgodonoa         ###   ########.fr       */
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