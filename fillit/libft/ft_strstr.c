/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 20:11:07 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/20 21:40:01 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (str2[j] == '\0')
		return ((char *)&str1[i]);
	while (str1[i] != '\0')
	{
		while (str1[i] == str2[j] && str1[i] != '\0')
		{
			if (str1[i] == str2[j] && str2[j + 1] == '\0')
				return ((char *)&str1[i - j]);
			i++;
			j++;
		}
		i = i - j;
		i++;
		j = 0;
	}
	return (0);
}
