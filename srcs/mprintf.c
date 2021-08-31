#include "libft.h"

void	mprintf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				ft_putstr(va_arg(args, char *));
			else if (format[i] == '%')
				ft_putchar(format[i]);
			else if (format[i] == 'd')
				ft_putnbr(va_arg(args, int));	
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(args);
}