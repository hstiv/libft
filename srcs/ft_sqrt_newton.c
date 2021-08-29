#include "libft.h"

static int pt2(const double nb, double upper, double lower)
{
	double			sqrt;

	while ((upper - lower) > SQRT_NEWTON_ACCURACY)
	{
		sqrt = (lower + upper) / 2;
		if (sqrt * sqrt > nb)
			upper = sqrt;
		else
			lower = sqrt;
	}
	return ((lower + upper) / 2);
}

double	ft_sqrt_newton(const double nb)
{
	double			lower;
	double			upper;

	if (nb < 0)
		return (-NAN);
	if (nb == 0)
		return (0.0);
	if (nb < 1)
	{
		lower = nb;
		upper = 1;
	}
	else
	{
		lower = 1;
		upper = nb;
	}
	return (pt2(nb, upper, lower));
}