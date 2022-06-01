/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:16:19 by mjhin             #+#    #+#             */
/*   Updated: 2021/12/15 12:45:05 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_args(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putadr(va_arg(args, unsigned long long)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_dec(va_arg(args, int)));
	else if (c == 'u')
		return (ft_unsigned_putnbr_dec(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned int), 'x'));
	else if (c == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned int), 'X'));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		size;
	int		i;

	va_start(args, str);
	size = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			size += ft_args(args, str[++i]);
		else
			size += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (size);
}
