/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-mawl <kal-mawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:14:30 by kal-mawl          #+#    #+#             */
/*   Updated: 2025/07/16 09:14:44 by kal-mawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	init_stack(t_stack **stack, char **args)
{
	long	value;
	t_stack	*new_node;

	while (*args)
	{
		value = ft_atol(*args);
		if (value > INT_MAX || value < INT_MIN)
		{
			free_stack(stack);
			exit(1);
		}
		new_node = stack_new((int)value);
		if (!new_node)
		{
			free_stack(stack);
			exit(1);
		}
		stack_add_back(stack, new_node);
		args++;
	}
}
