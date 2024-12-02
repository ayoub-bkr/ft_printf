/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:08:09 by aboukent          #+#    #+#             */
/*   Updated: 2024/12/02 14:48:27 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calcul(int i)
{
	int	len;

	len = 0;
	if (i == -2147483648)
		return (11);
	if (i == 0)
		len++;
	else if (i < 0)
	{
		len++;
		i *= -1;
	}
	while (i > 0)
	{
		i /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int	nb;

	nb = n + 48;
	if (n == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2147483648", 10);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(n * -1);
	}
	else if (n >= 0 && n <= 9)
		write(1, &nb, 1);
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (calcul(n));
}
