NAME = libftprintf.a

SRCFILE = format_eval.c \
ft_putchar_return_length.c \
put_nbr_return_length.c \
put_nbr_base.c \
ft_print_char.c \
ft_print_string.c \
ft_print_decimal.c \
ft_print_hex.c \
ft_print_pointer.c \
ft_print_uint.c

OBJFILE = $(SRCFILE:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJFILE)
	ar rcs $@ $^

$(OBJFILE): $(SRCFILE)
	$(CC) -c $(CFLAGS) $^

clean:
	rm -f $(OBJFILE)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
