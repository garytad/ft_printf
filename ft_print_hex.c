#include "ft_printf.h"

int	ft_print_hex(va_list args, const char c)
{
	unsigned int	n;
	int				i;

	i = 0;
	n = va_arg(args, unsigned int);
	if (c == 'x')
		i = put_nbr_base(n, "0123456789abcdef");
	else if (c == 'X')
		i = put_nbr_base(n, "0123456789ABCDEF");
	return (i);
}
