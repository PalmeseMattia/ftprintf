#include "ftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		chars_printed;
	char	*next_stop;

	chars_printed = 0;
	va_start(arguments, format);
	while ((next_stop = ft_strchr(format,'%')) != NULL)
	{
		chars_printed += ft_putnstr_fd((char *)format, next_stop - format, 1);
		chars_printed += manage_conversion(next_stop + CHAR_SIZE, arguments);
		format = next_stop + (2 * CHAR_SIZE);
	}
	chars_printed += ft_putstr_fd((char *)format, 1);
	va_end(arguments);
	return (chars_printed);
}
