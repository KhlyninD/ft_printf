/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:02:46 by mjhin             #+#    #+#             */
/*   Updated: 2021/12/15 12:46:41 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	output_hex(unsigned int n, unsigned int sys, char *base)
{
	int	size;

	size = 0;
	if (n >= sys)
		size += output_hex(n / sys, sys, base);
	size += ft_putchar(base[n % sys]);
	return (size);
}

int	ft_putnbr_hex(int n, char x)
{
	if (x == 'x')
		return (output_hex(n, 16, "0123456789abcdef"));
	else
		return (output_hex(n, 16, "0123456789ABCDEF"));
}
