#include <stdarg.h>
#include <unistd.h>

/* print string from va list */
int	ft_print_string(va_list *args)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(*args, char *);
	while (str[i])
		write (1, &str[i++], 1);
	return (i);
}

/* print char from va list */
int	ft_print_char(va_list *args)
{
	char	c;
	int		i;

	c = (char)va_arg(*args, int);
	i = write(1, &c, 1);
	if (i > 0)
		return (i);
	return (0);
}

/* evaluate format specifier */
int	format_eval(const char c, va_list *args)
{
	if (c == 'c')
		return(ft_print_char(args));
	if (c == 's')
		return(ft_print_string(args));
}

/* check for format conversion and print string */
int	ft_vprintf(const char *format, va_list args)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i])
			{
				format_eval(format[i], &args);
			}
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	return (i);
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
	ft_printf("acccbcdef%s%c", "abd", '1');
	return (0);
}
