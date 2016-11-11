/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 14:24:33 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/07/11 14:24:35 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t		j;

	j = 0;
	if (n < 1)
		return (0);
	while (str1[j] == str2[j] && j < n && str1[j] != '\0')
		j++;
	return (str1[j] - str2[j]);
}
