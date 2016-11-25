/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:54:05 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/20 20:54:11 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size_buf)
{
	size_t	i;
	size_t	size_dest;

	i = 0;
	size_dest = 0;
	while (dest[size_dest] != '\0' && size_dest < size_buf)
		size_dest++;
	while (size_dest < size_buf - 1 && src[i] != '\0')
	{
		dest[size_dest] = src[i];
		size_dest++;
		i++;
	}
	if (i > 0)
		dest[size_dest] = '\0';
	return ((size_dest - i) + ft_strlen(src));
}
