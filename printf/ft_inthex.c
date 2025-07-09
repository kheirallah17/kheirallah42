/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-mawl <kal-mawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 08:38:08 by kal-mawl          #+#    #+#             */
/*   Updated: 2025/07/02 08:39:08 by kal-mawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_lower(unsigned int n)
{
	char	hex_digit;

	if (n >= 16)
		ft_puthex_lower(n / 16);
	hex_digit = "0123456789abcdef"[n % 16];
	ft_putchar_fd(hex_digit, 1);
}

void	ft_puthex_large(unsigned int n)
{
	char	hex_digit;

	if (n >= 16)
		ft_puthex_large(n / 16);
	hex_digit = "0123456789ABCDEF"[n % 16];
	ft_putchar_fd(hex_digit, 1);
}

int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_inthex_lower(unsigned int x)
{
	int	count;

	count = 0;
	ft_puthex_lower(x);
	count += ft_hex_len(x);
	return (count);
}

int	ft_inthex_large(unsigned int x)
{
	int	count;

	count = 0;
	ft_puthex_large(x);
	count += ft_hex_len(x);
	return (count);
}
