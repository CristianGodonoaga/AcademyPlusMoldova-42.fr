/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:57:42 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/12 19:58:21 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	char	*temp;
	int		i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen((char *)s);
	temp = (char *)malloc(sizeof(temp) * len + 1);
	i = 0;
	while (*s != '\0')
		temp[i++] = f(*s++);
	temp[i] = '\0';
	return (temp);
}