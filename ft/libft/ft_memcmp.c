#include "libft.h"

int	ft_memcmp(const void *memptr1, const void *memptr2, size_t num)
{
    if(num <= 0)
        return (0);
    while (*((char *)(memptr1)) == *((char *)(memptr2)) && --num > 0)
    {
        memptr1++;
        memptr2++;
    }
    return (*((char *)(memptr1)) - *((char *)(memptr2)));
}
