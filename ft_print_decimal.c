#include "ft_printf.h"

/* print decimal from va list */
int	ft_print_decimal(va_list args)
{
	int	c;
	int	i;

	i = 0;
	c = va_arg(args, int);
	i = put_nbr_return_length(c);
	return (i);
}
