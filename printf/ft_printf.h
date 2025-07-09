/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-mawl <kal-mawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 08:46:39 by kal-mawl          #+#    #+#             */
/*   Updated: 2025/07/02 09:12:44 by kal-mawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

int			ft_printf(const char *str, ...);
int			ft_pointer(void *p, int fd);
int			test3(char *str, va_list args);
int			test2(char *str, va_list args);
int			ft_hex_len(unsigned int n);
int			ft_inthex_lower(unsigned int x);
int			test(char *str, va_list args);
int			numlen(int n);
int			ft_inthex_large(unsigned int x);

int			ft_puthex_ptr(unsigned long n, int fd);
int			ft_putunsigned_fd(unsigned int n, int fd);
void		ft_puthex_lower(unsigned int n);
void		ft_puthex_large(unsigned int n);
size_t		ft_strlen(const char *s);

int			ft_putchar_fd(char c, int fd);
int			ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
int			ft_putnbr_fd(int n, int fd);

#endif
