/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:06:36 by aboukent          #+#    #+#             */
/*   Updated: 2024/12/02 14:49:11 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	calcul(unsigned int i)
{
	int	len;

	len = 0;
	if (i == 0)
		len++;
	while (i > 0)
	{
		i /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_u(unsigned int n)
{
	unsigned int	nb;

	nb = n + 48;
	if (n > 9)
	{
		ft_putnbr_u(n / 10);
		ft_putnbr_u(n % 10);
	}
	else
		write(1, &nb, 1);
	return (calcul(n));
}
