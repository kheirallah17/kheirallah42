/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-mawl <kal-mawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 08:44:21 by kal-mawl          #+#    #+#             */
/*   Updated: 2025/07/02 08:44:29 by kal-mawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putunsigned_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
	return (count + 1);
}
