#include "ft_printf.h"

int	ft_print_pointer(va_list args)
{
	int		i;
	void	*ptr;

	ptr = va_arg(args, void *);
	i = write(1, "0x", 2);
	i += put_nbr_base((unsigned long long)ptr, "0123456789abcdef");
	return (i);
}
