#include "philo.h"

int	write_stuff(t_args *args, int i)
{
	char	*msg;
	t_philo philo;

	if (pthread_mutex_lock(&args->msg) != 0)
		return (printf("WTF\n"));
	philo = args->philo[i];
	if (!args->dead_man)
	{
		args->time = set_time() - args->start;
		msg = compose_message(args, i);
		printf("%lu ms %d %s", args->time, philo.id + 1, msg);
	}
	else if (args->end)
	{
		printf("%lu ms all done\n", args->time);
	}
	if (pthread_mutex_unlock(&args->msg) != 0)
		return (printf("UNWTF\n"));
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
	return ("stuck\n");
}
