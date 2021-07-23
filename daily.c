#include "philo.h"

void	sleep_think(t_args *args, int i)
{
	if (args->philo[i].status == SLEEP)
	{
		write_stuff(args, i);
		usleep(args->tts);
		args->philo[i].status = THINKING;
	}
	else if (args->philo[i].status == THINKING)
	{
		write_stuff(args, i);
		args->philo[i].status = SLEEP;
	}
}

static void	take_forks(t_args *args, int id, int id_2)
{
	pthread_mutex_lock(&args->forks[id_2]);
	args->philo[id].status = L_FORK;
	write_stuff(args, id);
	pthread_mutex_lock(&args->forks[id]);
	args->philo[id].status = R_FORK;
	write_stuff(args, id);
}

static void	drop_forks(t_args *args, int id, int id_2)
{
	pthread_mutex_unlock(&args->forks[id]);
	pthread_mutex_unlock(&args->forks[id_2]);
	args->philo[id].status = SLEEP;
}

void	lunch(t_args *args, int id)
{
	int		id_2;

	id_2 = (id - 1);
	if (id == 0)
		id_2 = args->phil_num - 1;
	pthread_mutex_lock(&args->forks[id]);
	args->philo[id].status = L_FORK;
	write_stuff(args, id);
	pthread_mutex_lock(&args->forks[id_2]);
	args->philo[id].status = R_FORK;
	write_stuff(args, id);
	args->philo[id].status = EATING;
	args->philo[id].last_meal = set_time();
	write_stuff(args, id);
	usleep(args->tte);
	args->philo[id].finish++;
	args->philo[id].status = SLEEP;
	pthread_mutex_unlock(&args->forks[id]);
	pthread_mutex_unlock(&args->forks[id_2]);
}
