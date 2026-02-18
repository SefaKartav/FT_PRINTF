/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekartav <sekartav@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 04:03:39 by sekartav          #+#    #+#             */
/*   Updated: 2026/02/18 19:25:25 by sekartav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int c)
{
	int		i;
	long	nb;

	i = 0;
	nb = c;
	if (nb < 0)
	{
		i += write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		i += ft_putnbr(nb / 10);
	i += write(1, &"0123456789"[nb % 10], 1);
	return (i);
}

int	ft_putnbrl(unsigned int c)
{
	int	i;

	i = 0;
	if (c >= 10)
		i += ft_putnbrl(c / 10);
	i += write(1, &"0123456789"[c % 10], 1);
	return (i);
}

int	ft_puthexp(void *c)
{
	unsigned long	a;
	int				i;

	i = 0;
	if (c == NULL)
		return (write(1, "(nil)", 5));
	a = (unsigned long)c;
	i += write(1, "0x", 2);
	i += ft_puthexl(a);
	return (i);
}
