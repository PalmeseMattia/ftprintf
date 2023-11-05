#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

#define CHAR_SIZE CHAR_BIT/8

void prints(const char *string, size_t size);
int ft_printf(const char *format, ...);
void manage_conversion(char *conversion);

int main()
{
	int result = ft_printf("lo zio %c la zia\n");
	printf("chars printed: %d\n", result);
	return 0;
}

int ft_printf(const char *format, ...)
{
	char *next_stop;
	int chars_printed = 0;
	while((next_stop = ft_strchr(format,'%')) != NULL){
		prints(format, next_stop-format);
		chars_printed += (next_stop-format)/CHAR_SIZE;
		manage_conversion(next_stop + CHAR_SIZE);
		format = next_stop + (2 * CHAR_SIZE);
	}
	prints(format, ft_strlen(format));
}

/**
 * Write to the stdout
*/
void prints(const char *string, size_t size)
{
	write(1, string, size);	
}

void manage_conversion(char *conversion)
{
	putchar(*conversion);
}


