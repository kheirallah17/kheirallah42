#include "philo.h"

static int	init_mutexes(t_sim *sim)
{
	int	i;

	if (pthread_mutex_init(&sim->print_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&sim->stop_mutex, NULL))
		return (1);
	i = 0;
	while (i < sim->nb_philo)
	{
		if (pthread_mutex_init(&sim->forks[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

static int	allocate_memory(t_sim *sim)
{
	sim->forks = malloc(sizeof(pthread_mutex_t) * sim->nb_philo);
	if (!sim->forks)
		return (1);
	sim->philos = malloc(sizeof(t_philo) * sim->nb_philo);
	if (!sim->philos)
		return (1);
	return (0);
}

static void	init_philos(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->nb_philo)
	{
		sim->philos[i].id = i + 1;
		sim->philos[i].meals_eaten = 0;
		sim->philos[i].last_meal = 0;
		sim->philos[i].sim = sim;

		sim->philos[i].left_fork = &sim->forks[i];
		sim->philos[i].right_fork = &sim->forks[(i + 1) % sim->nb_philo];

		pthread_mutex_init(&sim->philos[i].meal_mutex, NULL);
		i++;
	}
}
int init_simulation(t_sim *sim)
{
    sim->stop = 0;

    if (allocate_memory(sim))
        return (printf("Error: malloc failed\n"), 1);

    if (init_mutexes(sim))
        return (printf("Error: mutex init failed\n"), 1);

    init_philos(sim);

    return (0);
}
