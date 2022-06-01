/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:52:58 by mjhin             #+#    #+#             */
/*   Updated: 2021/12/15 12:45:53 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	output_dec(long n, long sys, char *base)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		size += ft_putchar('-');
		n *= -1;
	}
	if (n >= sys)
		size += output_dec(n / sys, sys, base);
	size += ft_putchar(base[n % sys]);
	return (size);
}

int	ft_putnbr_dec(int n)
{
	return (output_dec(n, 10, "0123456789"));
}
