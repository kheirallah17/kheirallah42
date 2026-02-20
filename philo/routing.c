#include "philo.h"

void	print_action(t_philo *p, char *msg)
{
	pthread_mutex_lock(&p->sim->print_mutex);
	if (!check_stop(p->sim))
		printf("%ld %d %s\n",
			get_time() - p->sim->start_time,
			p->id,
			msg);
	pthread_mutex_unlock(&p->sim->print_mutex);
}

static void	take_forks(t_philo *p)
{
	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(p->left_fork);
		print_action(p, "has taken a fork");
		pthread_mutex_lock(p->right_fork);
	}
	else
	{
		pthread_mutex_lock(p->right_fork);
		print_action(p, "has taken a fork");
		pthread_mutex_lock(p->left_fork);
	}
	print_action(p, "has taken a fork");
}

static void	eat(t_philo *p)
{
	pthread_mutex_lock(&p->meal_mutex);
	p->last_meal = get_time();
	p->meals_eaten++;
	pthread_mutex_unlock(&p->meal_mutex);
	print_action(p, "is eating");
	smart_sleep(p->sim->time_to_eat, p->sim);
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
}

static void	sleep_and_think(t_philo *p)
{
	print_action(p, "is sleeping");
	smart_sleep(p->sim->time_to_sleep, p->sim);
	print_action(p, "is thinking");
}

void	*philosopher_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->sim->nb_philo == 1)
	{
		pthread_mutex_lock(p->left_fork);
		print_action(p, "has taken a fork");
		smart_sleep(p->sim->time_to_die, p->sim);
		pthread_mutex_unlock(p->left_fork);
		return (NULL);
	}
	if (p->id % 2 == 0)
		usleep(1000);
	while (!check_stop(p->sim))
	{
		take_forks(p);
		eat(p);
		sleep_and_think(p);
	}
	return (NULL);
}
