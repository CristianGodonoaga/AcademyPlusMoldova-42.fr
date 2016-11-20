/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:42:41 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/19 17:53:53 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	temp[12];
	size_t	i;
	int		byte;

	i = ft_count_digit(n);
	if (n < 0){
		i++;
		temp[0] = '-';
	}
	else
	{
		n *= -1;
		temp[0] = '0';
	}
	byte = i;
	temp[i--] = '\0';
	while (n)
	{
		temp[i--] = (n % 10)*(1 - 2 *(n < 0)) + 48;
		n /= 10;
	}
	write(fd, temp, byte);
}
