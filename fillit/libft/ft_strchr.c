/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:45:33 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/19 17:48:20 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int s)
{
	int	i;

	i = 0;
	while (str[i] != (char)s && str[i] != '\0')
		i++;
	if (str[i] == (char)s)
		return ((char*)&str[i]);
	else
		return (NULL);
}
