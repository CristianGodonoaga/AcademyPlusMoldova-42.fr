/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:24:31 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/12/01 19:24:33 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	reverse_bits(unsigned char n)
{
	unsigned char	res;
	unsigned char	i;

	i = 8;
	res = 0;
	while (i)
	{
		res = (res << 1) | (n & 1);
		n >>= 1;
		i--;
	}
	return (res);
}
