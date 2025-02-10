/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzaazaa <firas.zaazaa@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:51:13 by fzaazaa           #+#    #+#             */
/*   Updated: 2025/02/10 15:11:33 by fzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putvoid(void *p)
{
	unsigned long	addr;
	char			*hex;
	char			*buffer;
	int				i;

	hex = (char *)malloc(sizeof(char) * 17);
	buffer = (char *)malloc(sizeof(char) * 17);
	if (!hex || !buffer)
		return (0);
	addr = (unsigned long)p;
	hex = ft_strcpy("0123456789abcdef", hex);
	buffer[16] = 0;
	i = 15;
	while (addr > 0)
	{
		buffer[i] = hex[addr % 16];
		addr /= 16;
		i--;
	}
	write(1, "0x", 2);
	write(1, &buffer[i + 1], 17 - i);
	return (17 - i);
}
