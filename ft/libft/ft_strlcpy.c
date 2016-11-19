/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 14:24:33 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/19 09:34:26 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	len;

	len = 0;
	while (*src++ != '\0')
		len++;
	if (size == 0)
		return (len);
	*dest = '\0';
	src = src - len - 1;
	while (*src != '\0' && --size > 0)
		*dest++ = *src++;
	*dest = '\0';
	return (len);
}
