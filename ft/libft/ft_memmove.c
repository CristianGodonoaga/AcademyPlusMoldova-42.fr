/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:26:59 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/16 16:45:55 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destptr, const void *srcptr, size_t num)
{
	char	*dest;
	char	*src;

	dest = (char*)destptr;
	src = (char*)srcptr;
	num--;
	while ((int)num >= 0)
	{
		dest[num] = src[num];
		num--;
	}
	return (destptr);
}