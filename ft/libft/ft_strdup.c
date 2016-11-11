#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;

	if (!s1)
		return (NULL);
	copy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!copy)
		return (NULL);
	return (ft_strcpy(copy, s1));
}
