/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodonoa <cgodonoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 20:03:33 by cgodonoa          #+#    #+#             */
/*   Updated: 2016/11/19 18:30:32 by cgodonoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int s)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != (char)s && i >= 0)
		i--;
	if (i >= 0 && str[i] == (char)s)
		return (&str[i]);
	return (0);
}
