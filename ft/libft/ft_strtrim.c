/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 20:12:42 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/13 18:06:14 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*temp;

	i = 0;
	while ((s[i] == ' ' || s[i] == ',' || s[i] == '\t' ||
		s[i] == '\n') && s[i] != '\0')
		i++;
	j = i;
	while (s[j] != '\0')
		j++;
	k = j;
	while ((s[k - 1] == ' ' || s[k - 1] == ',' || s[k - 1] == '\t' ||
		s[k - 1] == '\n') && k != 0)
		k--;
	temp = (char *)malloc(sizeof(char) * (j - i - (j - k)) + 1);
	if (!temp)
		return (NULL);
	j = j - (j - k);
	k = 0;
	while (i < j)
		temp[k++] = s[i++];
	temp[k] = '\0';
	return (temp);
}