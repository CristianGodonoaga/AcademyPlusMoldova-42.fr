#include "libft.h"

void	*ft_memchr(const void *memptr, int value, size_t num)
{
    size_t i;

    i = 0;
    while (i < num)
    {
        if (*((char*)memptr + i) == ((unsigned char)value))
            return((void*)(memptr + i));
        i++;
    }
    return (0);
}
