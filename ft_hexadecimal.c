/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:06:05 by aboukent          #+#    #+#             */
/*   Updated: 2024/12/09 18:04:02 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexadecimal(unsigned int i, char c)
{
	char	*hd;
	int		len;

	len = 0;
	if (c == 'x')
	{
		hd = "0123456789abcdef";
		if (i / 16 > 0)
			len += ft_hexadecimal(i / 16, c);
		ft_putchar(hd[i % 16]);
	}
	else if (c == 'X')
	{
		hd = "0123456789ABCDEF";
		if (i / 16 > 0)
			len += ft_hexadecimal(i / 16, c);
		ft_putchar(hd[i % 16]);
	}
	len++;
	return (len);
}
