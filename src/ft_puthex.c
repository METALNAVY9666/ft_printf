/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzaazaa <firas.zaazaa@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:49:17 by fzaazaa           #+#    #+#             */
/*   Updated: 2025/02/10 14:55:27 by fzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puthexupper(int nbr, int *count)
{
	char	*hex_digits;

	hex_digits = (char *)malloc(sizeof(char) * 16);
	hex_digits = ft_strcpy("0123456789ABCDEF", hex_digits);
	if (!hex_digits)
		return (0);
	if (nbr >= 16)
		ft_puthexupper(nbr / 16, count);
	write(1, &hex_digits[nbr % 16], 1);
	(*count)++;
	free(hex_digits);
	return (*count);
}

int	ft_puthexlower(int nbr, int *count)
{
	char	*hex_digits;

	hex_digits = (char *)malloc(sizeof(char) * 16);
	hex_digits = ft_strcpy("0123456789abcdef", hex_digits);
	if (!hex_digits)
		return (0);
	if (nbr >= 16)
		ft_puthexlower(nbr / 16, count);
	write(1, &hex_digits[nbr % 16], 1);
	(*count)++;
	free(hex_digits);
	return (*count);
}

int	ft_puthex(int nbr, int lower)
{
	int	total;

	total = 0;
	if (lower)
		ft_puthexlower(nbr, &total);
	else
		ft_puthexupper(nbr, &total);
	return (total);
}
