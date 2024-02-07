#ifndef FTPRINTF_H
#define FTPRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

#define CHAR_SIZE CHAR_BIT/8

int	ft_printf(const char *format, ...);
int ft_manage_conversion(char *conversion, va_list arguments);

#endif
