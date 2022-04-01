#include "ft_printf.h"

/* print char from va list */
int	ft_print_char(va_list args)
{
	char	c;
	int		i;

	c = (char)va_arg(args, int);
	i = write(1, &c, 1);
	if (i > 0)
		return (i);
	return (0);
}
