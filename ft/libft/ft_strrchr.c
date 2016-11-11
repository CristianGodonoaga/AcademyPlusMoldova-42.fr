#include"libft.h"

char	*ft_strrchr(char *str, int s)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while(str[i] != s && i >= 0)
		i--;
	if(i >= 0 && str[i] == s)
		return(&str[i]);
	return(0);
}
