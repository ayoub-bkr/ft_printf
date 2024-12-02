/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:15:15 by aboukent          #+#    #+#             */
/*   Updated: 2024/12/02 15:00:58 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put(int i, const char *s, va_list args)
{
	if (s[i + 1] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (s[i + 1] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (s[i + 1] == 'p')
		return (ft_address(va_arg(args, void *)));
	else if (s[i + 1] == 'd' || s[i + 1] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (s[i + 1] == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	else if (s[i + 1] == 'x' || s[i + 1] == 'X')
		return (ft_hexadecimal(va_arg(args, long), s[i + 1]));
	else if (s[i + 1] == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	args;
	va_list	argslen;
	int		len;

	i = 0;
	va_start(args, s);
	va_copy(argslen, args);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			len += put(i, s, args);
			i++;
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (len);
}
// #include <stdio.h>
// int	main()
// {
// 	char *s = "hello";
// 	// char c = 'n';
// 	// int nb = 2;
// 	// int i = -214748;
// 	// unsigned u = 2147;
// 	// int h = 461;
// 	// int	a = ft_printf("\n%u", (unsigned int)2147483648);
// 	// int b = printf("\n%u", (unsigned int)2147483648);
// 	// printf("\n%d %d", a, b);
// 	printf("%s", s);
// }
