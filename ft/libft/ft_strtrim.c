#include "libft.h"

char    *ft_strtrim(char const *s)
{
    int     i;
    int     j;
    int     k;
    char    *temp;

    i = 0;
    while (s[i] == ' ' && s[i] == ',' && s[i] == '\t' &&
            s[i] == '\n' && s[i] != '\0')
        i++;
    j = i;
    while (s[j] != '\0')
        j++;
    k = j;
    while (s[k] == ' ' && s[k] == ',' && s[k] == '\t' && s[k] == '\n' && k != 0)
        k--;
    temp = (char *)malloc(sizeof(s) * (j - i - k) + 1);
    if (!temp)
        return (NULL);
    j = j - k;
    k = 0;
    while (i < j)
        temp[k++] = s[i++];
    temp[k] = '\0';
    return (temp);
}
