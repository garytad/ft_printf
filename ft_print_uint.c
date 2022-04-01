#include "ft_printf.h"

int	ft_print_uint(va_list args)
{
	unsigned int	c;
	int				i;

	i = 0;
	c = va_arg(args, unsigned int);
	i = put_nbr_base(c, "0123456789");
	return(i);
}
