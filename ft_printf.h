/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmese <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:53:00 by dpalmese          #+#    #+#             */
/*   Updated: 2024/02/12 12:54:03 by dpalmese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define CHAR_SIZE 1

int	ft_printf(const char *format, ...);
int	ft_manage_conversion(char *conversion, va_list arguments);

#endif
