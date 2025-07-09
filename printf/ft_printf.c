/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-mawl <kal-mawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 08:50:26 by kal-mawl          #+#    #+#             */
/*   Updated: 2025/07/02 09:48:08 by kal-mawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	test3(char *str, va_list args)
{
	int	count;

	count = 0;
	if (*str == 'u')
	{
		count += ft_putunsigned_fd(va_arg(args, unsigned int), 1);
	}
	else if (*str == 'p')
		count += ft_pointer(va_arg(args, void *), 1);
	else if (*str == 'x')
		count += ft_inthex_lower(va_arg(args, unsigned int));
	else if (*str == 'X')
		count += ft_inthex_large(va_arg(args, unsigned int));
	return (count);
}

int	test2(char *str, va_list args)
{
	int		count;
	int		val;
	char	*s;

	count = 0;
	if (*str == 's')
	{
		s = va_arg(args, char *);
		count += ft_putstr_fd(s, 1);
	}
	else if (*str == 'd' || *str == 'i')
	{
		val = va_arg(args, int);
		count += ft_putnbr_fd(val, 1);
	}
	else
	{
		count += test3(str, args);
	}
	return (count);
}

int	test(char *str, va_list args)
{
	int		count;
	char	k;

	count = 0;
	if (*str == 'c')
	{
		k = (char)va_arg(args, int);
		count += ft_putchar_fd(k, 1);
	}
	else if (*str == '%')
	{
		ft_putchar_fd('%', 1);
		count++;
	}
	else
	{
		count += test2(str, args);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += test((char *)str, args);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			count++;
		}
		str++;
	}
	va_end(args);
	return (count);
}
