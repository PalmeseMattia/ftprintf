#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"

#define CHAR_SIZE CHAR_BIT/8

int ft_printf(const char *format, ...);
int manage_conversion(char *conversion, va_list arguments);

int main()
{
	ft_printf(	"lo zio%c %c %s zia. Sono sposati da %d anni.\n",
				',','e',"la bella", -10);
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
	{
		int character = va_arg(arguments, int);
		return (ft_putchar_fd((char)character, 1));
	}
	else if (*conversion == 's')
	{
		char *string = va_arg(arguments, char*);
		return (ft_putstr_fd(string, 1));
	}
	else if (*conversion == 'd')
	{
		int number =va_arg(arguments, int);
		if(number < 0)
			return (ft_putnbrbase_fd(number, 10, 1) + 1);
		else
			return (ft_putnbrbase_fd(number, 10, 1));
	}
	else
		return (0);
}


