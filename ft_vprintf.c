#include "ft_printf.h"

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
