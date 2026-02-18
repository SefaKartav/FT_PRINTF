/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekartav <sekartav@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 01:22:45 by sekartav          #+#    #+#             */
/*   Updated: 2026/02/18 19:25:29 by sekartav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEX_LOW "0123456789abcdef"
# define HEX_UPP "0123456789ABCDEF"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int a);
int	ft_putstr(char *a);
int	ft_putnbr(int n);
int	ft_putnbrl(unsigned int n);
int	ft_puthexb(unsigned int a, char *base);
int	ft_puthexk(unsigned int a, char *base);
int	ft_puthexl(unsigned long a);
int	ft_puthexp(void *c);

#endif