/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 23:08:23 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/18 23:08:28 by cgodonoa         ###   ########.fr       */
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