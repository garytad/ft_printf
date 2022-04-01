#include "ft_printf.h"

int	put_nbr_return_length(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		i = write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			i += write(1, "-", 1);
			n = -n;
		}
		if (n >= 10)
		{
			i += put_nbr_return_length((n / 10));
			i += put_nbr_return_length((n % 10));
		}
		if (n >= 0 && n <= 9)
			i += ft_putchar_return_length(n + '0');
	}
	return (i);
}
