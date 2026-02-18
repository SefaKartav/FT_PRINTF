/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekartav <sekartav@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 01:40:48 by sekartav          #+#    #+#             */
/*   Updated: 2026/02/18 19:25:17 by sekartav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_decision(int a, va_list arg)
{
	int	i;

	i = 0;
	if (a == 'c')
		i += ft_putchar(va_arg(arg, int));
	else if (a == 's')
		i += ft_putstr(va_arg(arg, char *));
	else if (a == 'p')
		i += ft_puthexp(va_arg(arg, void *));
	else if (a == 'd' || a == 'i')
		i += ft_putnbr(va_arg(arg, int));
	else if (a == 'u')
		i += ft_putnbrl(va_arg(arg, unsigned int));
	else if (a == 'x')
		i += ft_puthexk(va_arg(arg, unsigned int), HEX_LOW);
	else if (a == 'X')
		i += ft_puthexb(va_arg(arg, unsigned int), HEX_UPP);
	else if (a == '%')
		i += write(1, "%", 1);
	else
		return (-1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		a;
	va_list	args;

	i = 0;
	if (format == 0)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			a = ft_decision(*(++format), args);
			if (a == -1)
				return (va_end(args), -1);
			i += a;
		}
		else if (*format != '%')
			i += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (i);
}
