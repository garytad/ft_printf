#include "ft_printf.h"

/* print char and return length*/
int	ft_putchar_return_length(char c)
{
	int	i;

	i = write(1, &c, 1);
	if (i < 0)
		return (0);
	return (i);
}
