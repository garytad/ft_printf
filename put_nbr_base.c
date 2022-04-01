#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	put_nbr_base(unsigned long n, char *base)
{
	int				i;
	unsigned long	base_len;

	base_len = ft_strlen(base);
	i = 0;
	if (n >= base_len)
	{
		i += put_nbr_base(n / base_len, base);
		i += put_nbr_base(n % base_len, base);
	}
	if (n < base_len)
		i += ft_putchar_return_length(base[n]);
	return (i);
}
