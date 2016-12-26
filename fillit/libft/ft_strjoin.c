/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:52:19 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/21 17:45:57 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*temp;

	if (!s1 || !s2)
		return (NULL);
	temp = (char *)malloc(sizeof(temp) * (ft_strlen((char *)s1) +
	ft_strlen((char *)s2)) + 1);
	if (!temp)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		temp[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		temp[i] = s2[j];
		i++;
		j++;
	}
	temp[i] = '\0';
	return (temp);
}
