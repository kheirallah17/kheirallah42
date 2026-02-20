#include "philo.h"

static int	check_all_ate(t_sim *sim)
{
	int	i;
	int	all_ate;

	if (sim->must_eat == -1)
		return (0);
	all_ate = 1;
	i = 0;
	while (i < sim->nb_philo)
	{
		pthread_mutex_lock(&sim->philos[i].meal_mutex);
		if (sim->philos[i].meals_eaten < sim->must_eat)
			all_ate = 0;
		pthread_mutex_unlock(&sim->philos[i].meal_mutex);
		i++;
	}
	return (all_ate);
}

static void	handle_death(t_sim *sim, int i, long now)
{
	pthread_mutex_lock(&sim->stop_mutex);
	sim->stop = 1;
	pthread_mutex_unlock(&sim->stop_mutex);
	pthread_mutex_lock(&sim->print_mutex);
	printf("%ld %d died\n", now - sim->start_time, sim->philos[i].id);
	pthread_mutex_unlock(&sim->print_mutex);
}

static int	check_philosopher_death(t_sim *sim, int i)
{
	long	now;

	pthread_mutex_lock(&sim->philos[i].meal_mutex);
	now = get_time();
	if (now - sim->philos[i].last_meal > sim->time_to_die)
	{
		pthread_mutex_unlock(&sim->philos[i].meal_mutex);
		handle_death(sim, i, now);
		return (1);
	}
	pthread_mutex_unlock(&sim->philos[i].meal_mutex);
	return (0);
}

static int	check_all_philos(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->nb_philo)
	{
		if (check_philosopher_death(sim, i))
			return (1);
		i++;
	}
	return (0);
}

void	monitor_philosophers(t_sim *sim)
{
	while (1)
	{
		pthread_mutex_lock(&sim->stop_mutex);
		if (sim->stop)
		{
			pthread_mutex_unlock(&sim->stop_mutex);
			return ;
		}
		pthread_mutex_unlock(&sim->stop_mutex);
		if (check_all_ate(sim))
		{
			pthread_mutex_lock(&sim->stop_mutex);
			sim->stop = 1;
			pthread_mutex_unlock(&sim->stop_mutex);
			return ;
		}
		if (check_all_philos(sim))
			return ;
		usleep(1000);
	}
}