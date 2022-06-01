/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:49:16 by mjhin             #+#    #+#             */
/*   Updated: 2021/12/15 12:45:20 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	output_adr(unsigned long long n, unsigned long long sis, char *base)
{
	int	l;

	l = 0;
	if (n >= sis)
		l += output_adr(n / sis, sis, base);
	l += ft_putchar(base[n % sis]);
	return (l);
}

int	ft_putadr(unsigned long long n)
{
	int	l;

	l = 0;
	l += ft_putstr("0x");
	if (n == 0)
		l += ft_putchar('0');
	else
		l += output_adr(n, 16, "0123456789abcdef");
	return (l);
}
