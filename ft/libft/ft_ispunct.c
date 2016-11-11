#include "libft.h"

int	ft_ispunct(int c)
{
	if( c == '.' || c == ',' ||
		c == ';' || c == ':'||
			 c == '!' || c == '?')
		return(1);
	else
		return (0);
}
