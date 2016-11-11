#include"libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (str1[i] != '\0' && *str1 != '\0')
	{
		j = 0;
		while (str1[i] == str2[j] && str2[j] != '\0')
		{
			i++;
			j++;
		}
	if (str1[i] == str2[j] && str1[j] == '\0')
		return ((char *) &str1[i]);
	i++;
	}
	return NULL;
}
