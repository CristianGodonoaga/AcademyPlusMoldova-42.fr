/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 20:12:42 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/21 18:05:39 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_count_delimite(const char *s)
{
	size_t	i;

	i = 0;
	while ((s[i] == ' ' || s[i] == ',' || s[i] == '\t' ||
		s[i] == '\n') && s[i] != '\0')
		i++;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*temp;

	if (!s)
		return (NULL);
	i = ft_count_delimite(s);
	j = i;
	while (s[j] != '\0')
		j++;
	k = j;
	while ((s[k - 1] == ' ' || s[k - 1] == ',' || s[k - 1] == '\t' ||
		s[k - 1] == '\n') && k != 0 && k != i)
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
