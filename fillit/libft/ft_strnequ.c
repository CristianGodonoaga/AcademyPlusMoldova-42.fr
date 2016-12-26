/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 20:01:28 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/21 17:35:13 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (!s1 || !s2)
		return (0);
	while (s1[i] == s2[i] && i + 1 < n && s1[i] != '\0')
		i++;
	if (s1[i] == s2[i])
		return (1);
	else
		return (0);
}
