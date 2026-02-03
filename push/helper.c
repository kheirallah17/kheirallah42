/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khairallahmawla <khairallahmawla@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:16:40 by kal-mawl          #+#    #+#             */
/*   Updated: 2025/07/21 09:18:17 by khairallahm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static void	check_limits(long result, int sign)
{
	if ((sign == 1 && result > INT_MAX)
		|| (sign == -1 && - result < INT_MIN))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		result = result * 10 + (str[i++] - '0');
		check_limits(result, sign);
	}
	return ((int)(result * sign));
}

void free_split(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}
