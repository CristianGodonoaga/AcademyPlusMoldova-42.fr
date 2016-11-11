#include "libft.h"

char    *ft_strmap(char const *s, char (*f)(char))
{
    int     len;
    char    *temp;
    int i;

    if (!s || !f)
        return (NULL);
    len = ft_strlen((char *)s);
    temp = (char *)malloc(sizeof(temp) * len + 1);
    i = 0;
    while (*s != '\0')
        temp[i++] = f(*s++);
    temp[i] = '\0';
    return (temp);
}
