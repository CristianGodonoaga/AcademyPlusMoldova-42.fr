/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 20:08:30 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/13 01:07:58 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue;
		}
		while (s[i] != c && s[i])
			i++;
		j++;
	}
	return (j);
}

char	**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			**temp;

	temp = (char **)malloc(sizeof(temp) * ft_count_word(s,c) + 1);
	i = 0;
	k = 0;
	while (s[i] != '\0' && temp)
	{
		if(s[i] == c)
		{
			i++;
			continue;
		}
		j = i;
		while (s[j] != c && s[j])
			j++;
		temp[k] = ft_strsub(s, i, j - i);
		i = j;
		k++;
	}
	temp[k] = NULL;
	return (temp);
}