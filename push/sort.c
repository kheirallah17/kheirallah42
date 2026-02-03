/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khairallahmawla <khairallahmawla@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:10:15 by kal-mawl          #+#    #+#             */
/*   Updated: 2025/10/02 08:53:37 by khairallahm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}

void	sort_three(t_stack **a)
{
	int	max;

	max = find_max(*a);
	if ((*a)->value == max)
		ra(a, 1);
	else if ((*a)->next->value == max)
		rra(a, 1);
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	pos;

	pos = find_min(*a);
	if (pos <= stack_size(*a) / 2)
		while (pos--)
			ra(a, 1);
	else
		while (pos++ < stack_size(*a))
			rra(a, 1);
	pb(a, b, 1);
	sort_three(a);
	pa(a, b, 1);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	pos;

	pos = find_min(*a);
	if (pos <= stack_size(*a) / 2)
		while (pos-- > 0)
			ra(a, 1);
	else
		while (pos++ < stack_size(*a))
			rra(a, 1);
	pb(a, b, 1);
	pos = find_min(*a);
	if (pos <= stack_size(*a) / 2)
		while (pos-- > 0)
			ra(a, 1);
	else
		while (pos++ < stack_size(*a))
			rra(a, 1);
	pb(a, b, 1);
	sort_three(a);
	pa(a, b, 1);
	pa(a, b, 1);
}
