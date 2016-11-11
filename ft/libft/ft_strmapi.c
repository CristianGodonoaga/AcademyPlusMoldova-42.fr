#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    int     i;
    char    *temp;
    int     len;

    if(!s || !f)
        return (NULL);
    len = ft_strlen((char *)s);
    temp = (char *)malloc(sizeof(temp) * len +1);
    i = 0;
    while (s[i] != '\0')
    {
        temp[i] = f((unsigned int)i,s[i]);
        i++;
    }
    temp[i] = '\0';
    return (temp);
}
