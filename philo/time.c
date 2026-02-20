#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;
	long			milliseconds;

	gettimeofday(&tv, NULL);
	milliseconds = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (milliseconds);
}

int	check_stop(t_sim *sim)
{
	int	stop;

	pthread_mutex_lock(&sim->stop_mutex);
	stop = sim->stop;
	pthread_mutex_unlock(&sim->stop_mutex);
	return (stop);
}

void	smart_sleep(long time, t_sim *sim)
{
	long	start;

	start = get_time();
	while (!check_stop(sim))
	{
		if (get_time() - start >= time)
			break ;
		usleep(100);
	}
}

