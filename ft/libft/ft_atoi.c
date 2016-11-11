#include"libft.h"

int	ft_atoi(const char *str)
{
	int	nb;
	int	i;
	int	semn;

	nb = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	semn = 1;
	if(str[i] == '-')
	{
		semn = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while(str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb = nb + (str[i] - 48);
		i++;
	}
	return (nb * semn);
}
