#include "philo.h"

int	start_philosophers(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->nb_philo)
	{
		sim->philos[i].last_meal = sim->start_time;
		if (pthread_create(&sim->philos[i].thread, NULL,
				philosopher_routine, &sim->philos[i]))
			return (printf("Error: thread creation failed\n"), 1);
		i++;
	}
	return (0);
}

void	join_philosophers(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->nb_philo)
	{
		pthread_join(sim->philos[i].thread, NULL);
		i++;
	}
}

void	cleanup(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->nb_philo)
	{
		pthread_mutex_destroy(&sim->philos[i].meal_mutex);
		pthread_mutex_destroy(&sim->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&sim->print_mutex);
	pthread_mutex_destroy(&sim->stop_mutex);
	free(sim->philos);
	free(sim->forks);
}

int	main(int ac, char **av)
{
	t_sim	sim;

	if (ac != 5 && ac != 6)
		return (printf("invalid number of arguments\n"), 1);
	if (parse_input(&sim, ac, av))
		return (1);
	if (init_simulation(&sim))
		return (1);
	sim.start_time = get_time();
	if (start_philosophers(&sim))
		return (1);
	monitor_philosophers(&sim);
	join_philosophers(&sim);
	cleanup(&sim);
	return (0);
}