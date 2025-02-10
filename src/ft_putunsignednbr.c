/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzaazaa <firas.zaazaa@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:44:29 by fzaazaa           #+#    #+#             */
/*   Updated: 2025/02/10 15:26:04 by fzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	sub_ft_putunsignednbr(unsigned int nbr, int *total)
{
	char	c;

	c = 0;
	if (nbr < 10)
	{
		c = nbr + 48;
		write(1, &c, 1);
		(*total)++;
		return ;
	}
	sub_ft_putunsignednbr(nbr / 10, total);
	sub_ft_putunsignednbr(nbr % 10, total);
}

int	ft_putunsignednbr(unsigned int nbr)
{
	int	total;

	total = 0;
	sub_ft_putunsignednbr(nbr, &total);
	return (total);
}
