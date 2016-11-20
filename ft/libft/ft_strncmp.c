/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 14:24:33 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/19 18:27:29 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	j;

	j = 0;
	if (n < 1)
		return (0);
	while (str1[j] == str2[j] && j < n - 1 && str1[j] != '\0')
		j++;
	if ((unsigned char)str1[j] < (unsigned char)str2[j])
		return (-1);
	else if ((unsigned char)str1[j] > (unsigned char)str2[j])
		return (1);
	return (0);
}
