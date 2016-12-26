/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:27:43 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/21 18:42:14 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int c, size_t len)
{
	size_t	i;
	char	*temp_src;

	temp_src = (char *)src;
	i = 0;
	while (i < len)
	{
		temp_src[i] = (unsigned char)c;
		i++;
	}
	return (src);
}
