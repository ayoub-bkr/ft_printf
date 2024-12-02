/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:27:22 by aboukent          #+#    #+#             */
/*   Updated: 2024/12/02 14:31:52 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	calcul(unsigned long long l)
{
	char	*hd;
	int		len;

	hd = "0123456789abcdef";
	len = 0;
	if (l / 16 == 0)
	{
		write(1, "0x", 2);
		len += 2;
	}
	if (l / 16 > 0)
		len += calcul(l / 16);
	ft_putchar(hd[l % 16]);
	len++;
	return (len);
}

int	ft_address(void *a)
{
	unsigned long long	l;
	int					len;

	l = (unsigned long long)a;
	len = 0;
	if (!a)
		return (ft_putstr("(nil)"));
	else
		len = calcul(l);
	return (len);
}
