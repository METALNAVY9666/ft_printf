/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzaazaa <firas.zaazaa@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:43:00 by fzaazaa           #+#    #+#             */
/*   Updated: 2025/02/10 15:24:17 by fzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	sub_ft_putnbr(int nbr, int *count)
{
	char	c;

	c = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*count) = (*count) + 11;
		return ;
	}
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
		(*count)++;
	}
	if (nbr < 10)
	{
		c = nbr + 48;
		write(1, &c, 1);
		(*count)++;
		return ;
	}
	sub_ft_putnbr(nbr / 10, count);
	sub_ft_putnbr(nbr % 10, count);
}

int	ft_putnbr(int nbr)
{
	int	total;

	total = 0;
	sub_ft_putnbr(nbr, &total);
	return (total);
}
