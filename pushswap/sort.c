/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-mawl <kal-mawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:10:15 by kal-mawl          #+#    #+#             */
/*   Updated: 2025/07/15 08:39:23 by kal-mawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	sort_three(t_stack **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		sa(a, 1);
	else if (x > y && y > z)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (x > y && y < z && x > z)
		ra(a, 1);
	else if (x < y && y > z && x < z)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (x < y && y > z && x > z)
		rra(a, 1);
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	min;
	int	pos;

	min = find_min(*a);
	pos = find_position(*a, min);
	while ((*a)->value != min)
	{
		if (pos <= 2)
			ra(a, 1);
		else
			rra(a, 1);
	}
	pb(a, b, 1);
	sort_three(a);
	pa(a, b, 1);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	min;
	int	pos;

	min = find_min(*a);
	pos = find_position(*a, min);
	while ((*a)->value != min)
	{
		if (pos <= 2)
			ra(a, 1);
		else
			rra(a, 1);
	}
	pb(a, b, 1);
	sort_four(a, b);
	pa(a, b, 1);
}
