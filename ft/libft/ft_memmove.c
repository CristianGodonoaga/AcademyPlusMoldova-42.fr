#include"libft.h"

void    *ft_memmove(void *destptr, const void *srcptr, size_t num)
{
	size_t	i;
	char	*temp;
	char	*dest;
	char	*src;

	dest = (char*)destptr;
	src = (char*)srcptr;
	temp = (char *)malloc(sizeof(temp) * num);
	i = 0;
	while (i < num)
	{
		temp[i] = src[i];
		i++;
	}
	i = 0;
	while(i < num)
	{
		dest[i] = temp[i];
	i++;
	}
	free(temp);
	return (destptr);
}
