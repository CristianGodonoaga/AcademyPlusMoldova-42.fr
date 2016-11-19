/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 23:06:56 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/18 23:06:57 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *memptr1, const void *memptr2, size_t num)
{
	if (num <= 0)
		return (0);
	while (*((unsigned char *)(memptr1)) == *((unsigned char *)(memptr2)) && 
		--num > 0)
	{
		memptr1++;
		memptr2++;
	}
	return (*((unsigned char *)(memptr1)) - *((unsigned char *)(memptr2)));
}
