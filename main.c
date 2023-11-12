#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"

#define CHAR_SIZE CHAR_BIT/8

ssize_t prints(const char *src, size_t size);
int ft_printf(const char *format, ...);
void manage_conversion(char *conversion, va_list arguments);

int main()
{
	ft_printf("lo zio %c %s zia\n",'e', "la bella");
	return 0;
}

int ft_printf(const char *format, ...)
{
	va_list arguments;
	va_start(arguments, format);
	char *next_stop;
	int chars_printed = 0;

	while((next_stop = ft_strchr(format,'%')) != NULL){ // Search for the next % character
		prints(format, next_stop-format);
		chars_printed += (next_stop-format)/CHAR_SIZE;
		manage_conversion(next_stop + CHAR_SIZE, arguments);
		format = next_stop + (2 * CHAR_SIZE); // TODO:Test in case of two %% adiacent or %d%d for example
	}

	prints(format, ft_strlen(format));
	va_end(arguments);
}

/**
 * Write string to the stdout
*/
ssize_t prints(const char *src, size_t size)
{
	return write(1, src, size);	
}

/**
 * According to the C language specification, usual arithmetic conversions are applied 
 * to the unnamed arguments of variadic functions. 
 * Hence, any integer type shorter than int (e. g. bool, char and short) 
 * are implicitly converted int; float is promoted to double, etc.
 * Do what the compiler asks you for (use va_arg() with int as its second parameter), 
 * else your code will invoke undefined behavior.
*/
void manage_conversion(char *conversion, va_list arguments)
{
	switch (*conversion) {
	case 'c':
		int character = va_arg(arguments, int);
		prints((const char *)&character,1);
		break;
	case 's':
		char *string = va_arg(arguments, char*);
		prints((const char *)string, ft_strlen(string));
		break;
	default:
		break;
	}
}


