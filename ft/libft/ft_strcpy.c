/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:47:41 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/12 19:48:06 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;
	char	*temp_src;
	
	temp_src = (char *)src;
	i = 0;
	while (temp_src[i] != '\0')
	{
		dest[i] = temp_src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}