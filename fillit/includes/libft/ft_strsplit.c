/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 20:08:30 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/21 18:20:08 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(const char *s, char c)
{
	int				i;
	int				j;

	if (!s)
		return (0);
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

static int	ft_check(char c1, char c2, unsigned int *i)
{
	if (c1 == c2)
	{
		*i = *i + 1;
		return (1);
	}
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			**temp;

	if (!s)
		return (NULL);
	temp = (char **)malloc(sizeof(*temp) * ft_count_word(s, c) + 1);
	if (!temp)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i] != '\0' && s)
	{
		if (ft_check(s[i], c, &i))
			continue;
		j = i;
		while (s[j] != c && s[j])
			j++;
		temp[k++] = ft_strsub(s, i, j - i);
		i = j;
	}
	temp[k] = NULL;
	return (temp);
}
