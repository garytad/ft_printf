#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/* print char */
int	ft_putchar(char	c)
{
	int	i;
	i = write(1, &c, 1);
	if (i < 0)
		return (0);
	return (i);
}

/* print int number */
int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		i = write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			i += ft_putchar('-');
			n = -n;
		}
		if (n >= 10)
		{
			i +=ft_putnbr(n / 10);
			i += ft_putnbr(n % 10);
		}
		if (n >= 0 && n <= 9)
			i += ft_putchar(n + '0');
	}
	return (i);
}

/* print string from va list */
int	ft_print_string(va_list args)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(args, char *);
	while (str[i])
		write (1, &str[i++], 1);
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

	c = va_arg(args, int);
	i = ft_putnbr(c);
	return (i);
}
/* evaluate format specifier */
int	format_eval(const char c, va_list args)
{
	if (c == 'c')
		return(ft_print_char(args));
	if (c == 's')
		return(ft_print_string(args));
	if (c == 'd')
		return(ft_print_decimal(args));
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

int	main()
{
	int	i;

	i = ft_printf("acccbcdef%s%c%d", "abc", 'd', 1222);
	ft_printf("char printed = %d", i);
	return (0);
}
