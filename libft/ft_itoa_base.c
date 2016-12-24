/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:36:25 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/25 14:36:28 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_recurent(long nb, int base, char *str, int *i)
{
	if (nb == 0)
		return ;
	ft_recurent(nb / base, base, str, i);
	str[(*i)++] = "0123456789ABCDEF"[nb % base * (1 - 2 * (nb < 0))];
}

char			*ft_itoa_base(int value, int base)
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(char) * 64);
	if (!str)
		return (NULL);
	if (value == 0)
		str[i++] = '0';
	if (value < 0 && base == 10)
		str[i++] = '-';
	ft_recurent(value, base, str, &i);
	str[i] = '\0';
	return (str);
}
