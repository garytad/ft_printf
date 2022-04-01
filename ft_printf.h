#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	format_eval(const char c, va_list args);
int	ft_print_char(va_list args);
int	ft_print_string(va_list args);
int	ft_print_uint(va_list args);
int	ft_print_decimal(va_list args);
int	ft_print_hex(va_list args, const char c);
int	ft_print_pointer(va_list args);
int	ft_putchar_return_length(char c);
int	put_nbr_base(unsigned long n, char *base);
int	put_nbr_return_length(int n);

#endif
