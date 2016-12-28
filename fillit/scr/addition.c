#include "stdlib.h"

int			high_sqrt(int n)
{
	int		size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

char **get_array(int size)
{
	char 	**temp;
	int 	i;
	int 	j;

	temp = (char**)malloc(sizeof(char*) * size);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < size)
	{
		j = 0;
		*(temp + i) = (char *)malloc(sizeof(char) * size);
		if (!(temp + i))
			return (NULL);
		while (j < size)
		{
			*(*(temp + i) + j) = 0;
			j++;
		}
		i++;
	}
	return (temp);
}