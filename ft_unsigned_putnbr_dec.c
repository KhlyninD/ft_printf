/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr_dec.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:55:19 by mjhin             #+#    #+#             */
/*   Updated: 2021/12/15 12:47:12 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	output_unsigned_dec(unsigned int n, unsigned int sys, char *base)
{
	int	size;

	size = 0;
	if (n >= sys)
		size += output_unsigned_dec(n / sys, sys, base);
	size += ft_putchar(base[n % sys]);
	return (size);
}

int	ft_unsigned_putnbr_dec(unsigned int n)
{
	return (output_unsigned_dec(n, 10, "0123456789"));
}
