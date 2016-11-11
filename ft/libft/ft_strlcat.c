#include"libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	size_dest;

	i = 0;
	size_dest = ft_strlen(dest);
	if (size <= 0)
		return (size_dest);
	while (size_dest < size)
	{
		dest[size_dest] = src[i];
		size_dest++;
		i++;
	}
	dest[size_dest] = '\0';
	return (ft_strlen(dest));
}
