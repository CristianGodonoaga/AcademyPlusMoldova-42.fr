#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    int     i;
    int     j;
    char    *temp;
    int     len;

    if(!s1 || !s2)
        return (NULL);
    len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
    temp = (char *)malloc(sizeof(temp) * len + 1);
    i = 0;
    while (s1[i] != '\0')
    {
        temp[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j] != '\0')
    {
        temp[i] = s2[j];
        i++;
        j++;
    }
    temp[i] = '\0';
    return (temp);
}
