#include "swap.h"

static void	load_value(t_stack **stack, char *value,
	char **values, int free)
{
	int	nb;

	if (!is_valid_number(value))
	{
		free_stack(stack);
		if (free)
			free_split(values);
		exit_error();
	}
	nb = ft_atoi(value);
	if (has_duplicate(*stack, nb))
	{
		free_stack(stack);
		if (free)
			free_split(values);
		exit_error();
	}
	stack_add_back(stack, nb);
}

static void	new_stack(t_stack **stack, char **values, int free)
{
	int	i;

	i = 0;
	while (values[i])
	{
		load_value(stack, values[i], values, free);
		i++;
	}
	if (free)
		free_split(values);
}

void	ft_parse(t_stack **stack, int ac, char **av)
{
	char	**split;

	if (ac < 2)
		exit(0);
	if (ac == 2)
	{
		split = ft_split(av[1], " \t\n\r\v\f");
		if (!split)
		{
			free_stack(stack);
			exit_error();
		}
		new_stack(stack, split, 1);
	}
	else
		new_stack(stack, av + 1, 0);
}