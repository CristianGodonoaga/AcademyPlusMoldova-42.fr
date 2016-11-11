#include "libft.h"

void    *ft_memalloc(size_t size)
{
    char    *temp;

    if(size < 1)
        return (NULL);
    temp = (char*)malloc(sizeof(temp) * size);
    if (!temp)
        return (NULL);
    while (size-- > 0)
        *(temp + size) = 0;
    return ((void *)temp);
}
