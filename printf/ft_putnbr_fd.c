/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-mawl <kal-mawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 08:45:30 by kal-mawl          #+#    #+#             */
/*   Updated: 2025/07/02 08:45:41 by kal-mawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	int		cnt;

	cnt = 0;
	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
		cnt++;
	}
	if (nb >= 10)
		cnt += ft_putnbr_fd(nb / 10, fd);
	cnt += ft_putchar_fd(nb % 10 + '0', fd);
	return (cnt);
}
