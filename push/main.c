#include "swap.h"

void	dispatch_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	ft_parse(&a, ac, av);
	index_stack(a);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	dispatch_sort(&a, &b);
	free_stack(&a);
	return (0);
}
