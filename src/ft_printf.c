/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzaazaa <firas.zaazaa@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:47:37 by fzaazaa           #+#    #+#             */
/*   Updated: 2025/02/10 15:41:26 by fzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	handle_char(const char *str, int i, va_list args)
{
	if (str[i] == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (str[i] == 's')
		return (ft_putstr(va_arg(args, const char *)));
	if (str[i] == 'p')
		return (ft_putvoid(va_arg(args, void *)));
	if (str[i] == 'd' || str[i] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (str[i] == 'u')
		return (ft_putunsignednbr(va_arg(args, unsigned int)));
	if (str[i] == 'x')
		return (ft_puthex(va_arg(args, int), 1));
	if (str[i] == 'X')
		return (ft_puthex(va_arg(args, int), 0));
	if (str[i] == '%')
		return (ft_putchar('%'));
	return (0);
}

int	init_ft_printf(const char *format, int *i, int *total)
{
	if (!format)
		return (0);
	*i = 0;
	*total = 0;
	return (1);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	int			total;
	va_list		args;

	if (!init_ft_printf(format, &i, &total))
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			total = total + handle_char(format, i, args);
		}
		else
		{
			total++;
			write(1, &format[i], 1);
		}
		if (format[i])
			i++;
	}
	va_end(args);
	return (total);
}
