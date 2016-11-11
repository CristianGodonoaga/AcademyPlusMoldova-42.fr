/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 14:24:33 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/07/11 14:24:35 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;

	len = 0;
	while (*src++ != '\0')
		len++;
	if (size == 0)
		return (len);
	*dest = '\0';
	src = src - len - 1;
	while (*src != '\0' && --size > 0)
		*dest++ = *src++;
	*dest = '\0';
	return (len);
}
