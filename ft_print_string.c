#include "ft_printf.h"

int	ft_print_string(va_list args)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(args, char *);
	if (!str)
		i = write(1, "(null)", 6);
	else
	{
		while (str[i])
			write (1, &str[i++], 1);
	}
	return (i);
}
