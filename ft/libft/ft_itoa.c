/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:48:52 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/19 10:13:08 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	size_t		i;
	char		*temp;
	
	i = ft_count_digit(n);
	if (n < 0)
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (NULL);
	temp[i--] = '\0';
	if (n < 0)
	{
		n *= -1;
		temp[0] = '-';
	} 
	else
		temp[0] = '0';
	while (n)
	{
		temp[i--] = (n % 10)*(1 - 2 *(n < 0)) + 48;
		n /= 10;
	}
	return (temp);
}
