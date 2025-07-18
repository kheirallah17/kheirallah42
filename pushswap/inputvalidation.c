/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputvalidation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-mawl <kal-mawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:13:56 by kal-mawl          #+#    #+#             */
/*   Updated: 2025/07/16 09:52:40 by kal-mawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static int	is_valid_number(const char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_within_int(const char *s)
{
	long	n;

	n = ft_atol(s);
	return (n >= INT_MIN && n <= INT_MAX);
}

static int	has_duplicate(int cnt, char **tab)
{
	int		i;
	int		j;
	long	v_i;
	long	v_j;

	i = 0;
	while (i < cnt)
	{
		v_i = ft_atol(tab[i]);
		j = i + 1;
		while (j < cnt)
		{
			v_j = ft_atol(tab[j]);
			if (v_i == v_j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_input(int cnt, char **tab)
{
	int	i;

	if (cnt == 0)
		return (0);
	i = 0;
	while (i < cnt)
	{
		if (!is_valid_number(tab[i]) || !is_within_int(tab[i]))
			return (0);
		i++;
	}
	return (!has_duplicate(cnt, tab));
}
