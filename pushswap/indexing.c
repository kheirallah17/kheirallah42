/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-mawl <kal-mawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:12:11 by kal-mawl          #+#    #+#             */
/*   Updated: 2025/07/15 08:12:18 by kal-mawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static void	copy_values(t_stack *stack, int *array)
{
	int	i;

	i = 0;
	while (stack)
	{
		array[i++] = stack->value;
		stack = stack->next;
	}
}

static void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	find_index(int *array, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	index_stack(t_stack *stack)
{
	int		size;
	int		*array;
	t_stack	*temp;

	size = stack_size(stack);
	array = malloc(sizeof(int) * size);
	if (!array)
		exit(1);
	copy_values(stack, array);
	sort_array(array, size);
	temp = stack;
	while (temp)
	{
		temp->index = find_index(array, size, temp->value);
		temp = temp->next;
	}
	free(array);
}
