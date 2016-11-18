/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:48:52 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/16 22:17:30 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	long	nb;
	char	*temp;

	nb = n;
	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	(nb <= 0) ? (i++) : 0;
	temp = (char *)malloc( sizeof(temp) * (i + 1));
	if (!temp)
		return (NULL);
	temp[i--] = '\0';
	(nb < 0) ? (nb *= -1, temp[0] = '-') : (temp[0] = '0');
	while (nb)
	{
		temp[i--] = (unsigned char)(nb % 10) + 48;
		nb /= 10;
	}
	return (temp);
}
