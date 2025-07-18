/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-mawl <kal-mawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:44:22 by kal-mawl          #+#    #+#             */
/*   Updated: 2025/07/16 09:13:05 by kal-mawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static void	free_split(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

static void	exit_error(char **tab, int split_flag, t_stack **a)
{
	if (split_flag)
		free_split(tab);
	free_stack(a);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static char	**get_args(int ac, char **av, int *cnt, int *split_flag)
{
	char	**res;

	if (ac == 2)
	{
		res = ft_split(av[1], ' ');
		*split_flag = 1;
		if (!res || !*res)
			return (NULL);
		*cnt = 0;
		while (res[*cnt])
			(*cnt)++;
	}
	else
	{
		res = av + 1;
		*split_flag = 0;
		*cnt = ac - 1;
	}
	return (res);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int		cnt;
	int		split_f;

	if (ac == 1)
		return (0);
	a = NULL;
	b = NULL;
	args = get_args(ac, av, &cnt, &split_f);
	if (!args || !validate_input(cnt, args))
		exit_error(args, split_f, &a);
	init_stack(&a, args);
	if (split_f)
		free_split(args);
	index_stack(a);
	if (!is_sorted(a))
		radix_sort(&a, &b);
	free_stack(&a);
	return (0);
}
