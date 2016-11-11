#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	char		*temp_dest = (char *)dest;
	char		*temp_src = (char *)src;

	i = 0;
	while (i < n && temp_src[i] != c )
	{
		temp_dest[i] = temp_src[i];
		i++;
	}
	return (dest);
}
