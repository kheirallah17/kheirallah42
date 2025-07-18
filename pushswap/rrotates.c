/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotates.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-mawl <kal-mawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:27:41 by kal-mawl          #+#    #+#             */
/*   Updated: 2025/07/15 08:29:14 by kal-mawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	second_last = NULL;
	last = *stack;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **a, int print)
{
	reverse_rotate(a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int print)
{
	reverse_rotate(b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		write(1, "rrr\n", 4);
}
