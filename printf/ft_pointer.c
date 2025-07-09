/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-mawl <kal-mawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 08:40:03 by kal-mawl          #+#    #+#             */
/*   Updated: 2025/07/02 08:40:35 by kal-mawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_ptr(unsigned long n, int fd)
{
	char	*hex_digits;
	int		count;

	hex_digits = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex_ptr(n / 16, fd);
	ft_putchar_fd(hex_digits[n % 16], fd);
	return (++count);
}

int	ft_pointer(void *p, int fd)
{
	int				count;
	unsigned long	k;

	count = 0;
	if (p == NULL)
	{
		count += ft_putstr_fd("(nil)", fd);
	}
	else
	{
		count += ft_putstr_fd("0x", fd);
		k = (unsigned long)p;
		count += ft_puthex_ptr(k, fd);
	}
	return (count);
}
