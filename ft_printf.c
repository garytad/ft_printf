#include "ft_printf.h"

/* check for format conversion and print string */
static int	ft_vprintf(const char *format, va_list args)
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
