/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:38:18 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/16 21:18:43 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	nb;
	int	i;
	int	semn;

	nb = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	semn = 1;
	if (str[i] == '-')
	{
		semn = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nb > 0)
			nb *= 10;
		nb = nb + (str[i] - 48);
		i++;
	}
	return (nb * semn);
}
