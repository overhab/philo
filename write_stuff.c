#include "philo.h"

int	write_stuff(t_args *args, int i)
{
	char	*msg;
	t_philo philo;

	pthread_mutex_lock(&args->msg);
	philo = args->philo[i];
	if (!args->dead_man)
	{
		args->time = set_time() - args->start;
		msg = compose_message(args, i);
		printf("%lld\tms %d %s", set_time() - args->start, \
		philo.id + 1, msg);
	}
	pthread_mutex_unlock(&args->msg);
	return (1);
}

char	*compose_message(t_args *args, int id)
{
	if (args->philo[id].status == L_FORK)
		return (" has taken left fork\n");
	if (args->philo[id].status == R_FORK)
		return (" has taken right fork\n");
	if (args->philo[id].status == THINKING)
		return (" is thinking\n");
	if (args->philo[id].status == EATING)
		return (" is eating\n");
	if (args->philo[id].status == SLEEP)
		return (" is sleeping\n");
	return ("ERROR\n");
}
