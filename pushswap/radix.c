/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-mawl <kal-mawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:11:02 by kal-mawl          #+#    #+#             */
/*   Updated: 2025/07/15 08:39:46 by kal-mawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static int	get_max_bits(t_stack *stack)
{
	int	max;
	int	bits;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	bits;
	int	i;
	int	j;

	size = stack_size(*a);
	bits = get_max_bits(*a);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				ra(a, 1);
			else
				pb(a, b, 1);
			j++;
		}
		while (*b)
			pa(a, b, 1);
		i++;
	}
}
