/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-mawl <kal-mawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:09:57 by kal-mawl          #+#    #+#             */
/*   Updated: 2025/07/15 08:36:37 by kal-mawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	find_min(t_stack *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	find_position(t_stack *stack, int target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == target)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}
