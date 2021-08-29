#include "libft.h" 

double	ft_pow(double nb, uint8_t power)
{
	double		result;
	uint8_t		count;

	count = 0;
	result = 1;
	while (count < power)
	{
		result *= nb;
		count++;
	}
	return (result);
}
