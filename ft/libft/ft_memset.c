#include "libft.h"

void	*ft_memset(void *src, int c,  size_t n)
{
	size_t		i;
	char		*temp_src;
	
	temp_src = (char *)src;
	i = 0;
	while(i < n)
	{
		temp_src[i] = (unsigned char)c;
		i++;
	}
	return (src);
}
