/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 23:06:56 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/21 18:39:34 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t num)
{
	if (num <= 0)
		return (0);
	while (*((unsigned char *)(s1)) == *((unsigned char *)(s2)) &&
		--num > 0)
	{
		s1++;
		s2++;
	}
	return (*((unsigned char *)(s1)) - *((unsigned char *)(s2)));
}
