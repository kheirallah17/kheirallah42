#include "philo.h"
#include <stdio.h>

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+')
		i++;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(char *str)
{
	long	result;
	int		i;

	result = 0;
	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if (result > 2147483647)
			return (2147483648L);
		i++;
	}
	return (result);
}

int	parse_input(t_sim *sim, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_number(av[i]))
			return (printf("Error: arguments must be positive numbers\n"), 1);
		i++;
	}
	sim->nb_philo = (int)ft_atol(av[1]);
	sim->time_to_die = ft_atol(av[2]);
	sim->time_to_eat = ft_atol(av[3]);
	sim->time_to_sleep = ft_atol(av[4]);
	if (ac == 6)
		sim->must_eat = (int)ft_atol(av[5]);
	else
		sim->must_eat = -1;
	if (sim->nb_philo <= 0 || sim->time_to_die <= 0 || sim->time_to_eat <= 0
		|| sim->time_to_sleep <= 0 || (ac == 6 && sim->must_eat <= 0))
		return (printf("Error: invalid values\n"), 1);
	return (0);
}
