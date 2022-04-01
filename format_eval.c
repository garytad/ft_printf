#include "ft_printf.h"

/* evaluate format specifier */
int	format_eval(const char c, va_list args)
{
	if (c == 'c')
		return (ft_print_char(args));
	if (c == 's')
		return (ft_print_string(args));
	if (c == 'd' || c == 'i')
		return (ft_print_decimal(args));
	if (c == 'u')
		return (ft_print_uint(args));
	if (c == 'x' || c == 'X')
		return (ft_print_hex(args, c));
	if (c == 'p')
		return (ft_print_pointer(args));
	if (c == '%')
		return(ft_putchar_return_length('%'));
	return (0);
}
