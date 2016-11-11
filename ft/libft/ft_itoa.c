#include"libft.h"

char    *ft_itoa(int n)
{
    int     i;
    int     nb;
    char    *temp;

    nb = n;
    i = 0;
    while (nb != 0)
    {
        nb /= 10;
        i++;
    }
    (n <= 0) ? (i++) : 0;
    temp = (char *)malloc(sizeof(temp) * (i + 1));
    if (!temp)
        return (NULL);
    temp[i--] = '\0';
    (n < 0) ? (n*=-1, temp[0] = '-') : (temp[0] = '0');
    while (n)
    {
        temp[i--] = (unsigned char)(n % 10) + 48;
        n /= 10;
    }
    return (temp);
}
