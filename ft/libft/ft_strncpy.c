#include"libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	char	*temp_src;

	temp_src = (char *)src;
	i = 0;
	while (temp_src[i] != '\0' && i < n)
	{
		dest[i] = temp_src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
