#include "philo.h"

void	*monitoring(void *arg)
{
	t_args	*args;

	args = (t_args *)arg;
	while (!args->monitoring)
		;
	while (1)
	{
		if (is_dead(args))
			return (0);
		if (all_done(args))
			return (0);
	}
	return (0);
}

int	all_done(t_args *args)
{
	int		id;
	int		end;

	id = 0;
	end = 0;
	while (id < args->phil_num)
	{
		if (args->philo[id].finish)
			end++;
		id++;
	}
	if (end == id && args->eat_amount > 0)
	{
		args->end = 1;
		return (1);
	}
	return (0);
}

int	is_dead(t_args *args)
{
	int			id;
	long long	time;

	id = 0;
	while (id < args->phil_num)
	{
		if (((set_time() - args->philo[id].last_meal) * 1000 >= args->ttd))
		{
			args->dead_man = 1;
			args->philo[id].status = DEAD;
			pthread_mutex_unlock(&args->forks[id]);
			pthread_mutex_lock(&args->msg);
			time = set_time() - args->start;
			printf("%lld ms %d is dead\n", time, \
			args->philo[id].id + 1);
			pthread_mutex_unlock(&args->msg);
			return (1);
		}
		id++;
	}
	return (0);
}
