/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 04:36:06 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/14 17:51:21 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	int	j;

	j = 0;
	while (str1[j] == str2[j] && str2[j] != '\0')
		j++;
	if((unsigned char)str1[j] < (unsigned char)str2[j])
		return (-1);
	else if((unsigned char)str1[j] > (unsigned char)str2[j])
		return (1);
	return (0);
}