#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_sim	t_sim;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_sim			*sim;
}	t_philo;

typedef struct s_sim
{
    int             nb_philo;
    long            time_to_die;
    long            time_to_eat;
    long            time_to_sleep;
    int             must_eat;

    long            start_time;
    int             stop;

    pthread_mutex_t stop_mutex;
    pthread_mutex_t print_mutex;
    pthread_mutex_t *forks;

    t_philo         *philos;
}   t_sim;

int parse_input(t_sim *sim, int ac, char **av);
int init_simulation(t_sim *sim);
int check_stop(t_sim *sim);
long get_time(void);
void smart_sleep(long time, t_sim *sim);
void *philosopher_routine(void *arg);
void monitor_philosophers(t_sim *sim);
void print_action(t_philo *p, char *msg);
#endif
