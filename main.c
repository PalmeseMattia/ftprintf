#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "libft/libft.h"

#define CHAR_SIZE CHAR_BIT/8

int ft_printf(const char *format, ...);
int manage_conversion(char *conversion, va_list arguments);

int main()
{
	int result = ft_printf("%d\n", -150);
	ft_printf("Result: %d\n", result);
	return 0;
}

int ft_printf(const char *format, ...)
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

/*
 * According to the C language specification, usual arithmetic conversions are applied 
 * to the unnamed arguments of variadic functions. 
 * Hence, any integer type shorter than int (e. g. bool, char and short) 
 * are implicitly converted int; float is promoted to double, etc.
 * Do what the compiler asks you for (use va_arg() with int as its second parameter), 
 * else your code will invoke undefined behavior.
 */
int manage_conversion(char *conversion, va_list arguments)
{
	if (*conversion == 'c')
		return (ft_putchar_fd((char)va_arg(arguments, int), 1));
	else if (*conversion == 's')
		return (ft_putstr_fd(va_arg(arguments, char*), 1));
	else if (*conversion == 'd' || *conversion == 'i')
		return (ft_putstr_fd(ft_itoa(va_arg(arguments, int)), 1));
	else if (*conversion == 'x' || *conversion == 'X')
	{
		int number = va_arg(arguments, int);
		if (*conversion == 'x')
			return (ft_putnbrbase_fd(number, 16, 1)); //to lower
		else if (*conversion == 'X')
			return (ft_putnbrbase_fd(number, 16, 1));
	}
	else if (*conversion == 'u')
		return (ft_putnbrbase_fd(va_arg(arguments, unsigned int),10, 1));
	else
		return (0);
}
