/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmese <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:54:21 by dpalmese          #+#    #+#             */
/*   Updated: 2024/02/07 21:59:49 by rizz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

#define MASK(data, shift) (data >> (shift * 4) & 0xF)

/*
 * Write the address pointed by p to the file descriptor fd,
 * returning the number of characters printed.
 */
int	ft_putpointer_fd(void *p, int fd)
{
	uintptr_t			p_intvalue;
	int					i;
	int					result;
	unsigned char		byte;

	if(!p)
		return (ft_putchar_fd('0', fd));
	result = 0;
	i = (sizeof(p) * 2) - 1;
	p_intvalue = (uintptr_t) p;
	result += ft_putstr_fd("0x", fd);
	byte = MASK(p_intvalue, i);
	while (i >= 0 && byte == 0)
	{
		i--;
		byte = MASK(p_intvalue, i);
	}
	while (i >= 0)
	{
		byte = MASK(p_intvalue, i);
		result += ft_putnbrbase_fd((long)byte, 16, 1, 0);
		i--;
	}
	return (result);
}
