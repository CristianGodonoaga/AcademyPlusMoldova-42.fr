#include "libft.h"

char    *ft_strnew(size_t size)
{
    char    *temp;

    if (size < 1)
        return (NULL);
    temp = (char*)malloc(sizeof(temp) * size + 1);
    if (!temp)
        return (NULL);
    while ((size--)>0)
        *(temp + size) = '\0';
    return temp;
}

