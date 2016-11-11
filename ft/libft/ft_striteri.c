#include "libft.h"

void    ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    unsigned int i;

    i = 0;
    if(s && f)
        while (*s != '\0')
            f(i++,s);
}
