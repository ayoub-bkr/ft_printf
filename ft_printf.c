/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:15:15 by aboukent          #+#    #+#             */
/*   Updated: 2024/12/09 18:02:34 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put(const char *s, va_list args)
{
	if (*s == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*s == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*s == 'p')
		return (ft_address(va_arg(args, void *)));
	else if (*s == 'd' || *s == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (*s == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	else if (*s == 'x' || *s == 'X')
		return (ft_hexadecimal(va_arg(args, unsigned int), *s));
	else if (*s == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%' && *(s + 1) == '\0')
			return (-1);
		if (*s == '%' && (*(s + 1) == 'c' || *(s + 1) == 's' || *(s + 1) == 'p'
				|| *(s + 1) == 'd' || *(s + 1) == 'i' || *(s + 1) == 'u'
				|| *(s + 1) == 'x' || *(s + 1) == 'X' || *(s + 1) == '%'))
		{
			s++;
			len += put(s, args);
		}
		else
			len += ft_putchar(*s);
		s++;
	}
	va_end(args);
	return (len);
}
// #include <stdio.h>
// int	main()
// {
// 	//char *s = "yui";
// 	char c = 'n';
// 	//int d = 123;
// 	// int i = -214748;
// 	// unsigned u = 2147;
// 	// int h = 461;
// 	// int	a = ft_printf("\n%u", (unsigned int)2147483648);
// 	// int b = printf("\n%u", (unsigned int)2147483648);
// 	// printf("\n%d %d", a, b);
// 	int a = ft_printf("%c", c);
// 	printf("\n");
// 	int b = printf("%c", c);
// 	printf("\n%d|%d", a, b);
// }
