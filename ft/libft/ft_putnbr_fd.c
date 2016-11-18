/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:42:41 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/16 22:58:41 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	temp[12];
	int		i;
	long	nb;
	int		byte;

	nb = n;
	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	if (nb <= 0)
		i++;
	byte = i;
	temp[i--] = '\0';
	if (nb < 0)
		temp[0] = '-';
	else
	{
		nb *= -1;
		temp[0] = '0';
	}
	while (nb)
	{
		temp[i--] = ((~nb + 1) % 10) + 48;
		nb /= 10;
	}
	write(fd, temp, byte);
}