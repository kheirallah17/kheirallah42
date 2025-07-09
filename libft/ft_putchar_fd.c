/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-mawl <kal-mawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:57:42 by khairallahm       #+#    #+#             */
/*   Updated: 2025/05/29 07:58:14 by kal-mawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	if (c == '\0')
		return ;
	write(fd, &c, 1);
}

/*
void main(void) {
	ft_putchar_fd('X', 1); // X
}
*/