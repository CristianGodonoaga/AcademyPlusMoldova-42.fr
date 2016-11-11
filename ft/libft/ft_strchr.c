#include"libft.h"

char	*ft_strchr(const char *str, int s)
{
	int i;

	i = 0;
	while(str[i] != '\0' && str[i] != s)
		i++;

	if(str[i] == '\0')
		return(0);
	else
		return ((char*)&str[i]);
}
