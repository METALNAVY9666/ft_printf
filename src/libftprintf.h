/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzaazaa <firas.zaazaa@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:56:22 by fzaazaa           #+#    #+#             */
/*   Updated: 2025/02/10 14:53:44 by fzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_puthex(int nbr, int lower);
int		ft_putnbr(int nbr);
int		ft_putstr(const char *str);
int		ft_putunsignednbr(unsigned int nbr);
int		ft_putvoid(void *p);
char	*ft_strcpy(const char *src, char *dest);

#endif
