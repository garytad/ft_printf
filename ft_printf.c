#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

/* print char */
int	ft_putchar(char	c)
{
	int	i;
	i = write(1, &c, 1);
	if (i < 0)
		return (0);
	return (i);
}

int	put_nbr(int n)
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
			i += put_nbr((n / 10));
			i += put_nbr((n % 10));
		}
		if (n >= 0 && n <= 9)
			i += ft_putchar(n + '0');
	}
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
		i += ft_putchar(base[n]);
	return (i);
}

/* print string from va list */
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

/* print decimal from va list */
int	ft_print_decimal(va_list args)
{
	int	c;
	int	i;

	i = 0;
	c = va_arg(args, int);
	i = put_nbr(c);
	return (i);
}

int	ft_print_uint(va_list args)
{
	unsigned int	c;
	int				i;

	i = 0;
	c = va_arg(args, unsigned int);
	i = put_nbr_base(c, "0123456789");
	return(i);
}

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

int	ft_print_pointer(va_list args)
{
	int		i;
	void	*ptr;

	ptr = va_arg(args, void *);
	i = write(1, "0x", 2);
	i += put_nbr_base((unsigned long long)ptr, "0123456789abcdef");
	return (i);
}

/* evaluate format specifier */
int	format_eval(const char c, va_list args)
{
	if (c == 'c')
		return (ft_print_char(args));
	if (c == 's')
		return (ft_print_string(args));
	if (c == 'd')
		return (ft_print_decimal(args));
	if (c == 'u')
		return (ft_print_uint(args));
	if (c == 'x' || c == 'X')
		return (ft_print_hex(args, c));
	if (c == 'p')
		return (ft_print_pointer(args));
	if (c == '%')
		return(ft_putchar('%'));
	return (0);
}

/* check for format conversion and print string */
int	ft_vprintf(const char *format, va_list args)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i])
				ret += format_eval(format[i], args);
		}
		else
			ret += write(1, &format[i], 1);
		i++;
	}
	return (ret);
}

/* printf format conversion function */
int	ft_printf(const char *format, ...)
{
	va_list args;
	int		ret;

	va_start(args, format);
	ret = ft_vprintf(format, args);
	va_end(args);
	return (ret);
}
