/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekartav <sekartav@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 01:56:28 by sekartav          #+#    #+#             */
/*   Updated: 2026/02/18 19:41:23 by sekartav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int a)
{
	write(1, &a, 1);
	return (1);
}

int	ft_putstr(char *a)
{
	int	i;

	if (a == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (a[i])
	{
		write(1, &a[i], 1);
		i++;
	}
	return (i);
}

int	ft_puthexb(unsigned int a, char *base)
{
	int	x;
	x = 0;
	if (a >= 16)
		x += ft_puthexb(a / 16, base);
	x += write(1, &base[a % 16], 1);
	return (x);
}

int	ft_puthexk(unsigned int a, char *base)
{
	int	x;

	x = 0;
	if (a >= 16)
		x += ft_puthexk(a / 16, base);
	x += write(1, &base[a % 16], 1);
	return (x);
}

int	ft_puthexl(unsigned long a)
{
	char	*b;
	int		x;

	x = 0;
	b = "0123456789abcdef";
	if (a >= 16)
	{
		x += ft_puthexl(a / 16);
		x += ft_puthexl(a % 16);
	}
	else
		x += write(1, &b[a], 1);
	return (x);
}
