#include "libft.h"

void    ft_strclr(char *s)
{
    if (s)
    {
        while (*s != '\0')
        {
            *s = '\0';
            s++;
        }
    }
}
