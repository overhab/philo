#include "philo.h"

void	*monitoring(void *arg)
{
	t_args *args;

	args = (t_args *)arg;
	while (1)
	{
		if (is_dead(args))
			return (0);
		if (all_done(args))
			return (0);
		usleep(1000);
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
		args->time = set_time();
		if (args->philo[id].finish)
			end++;
		id++;
	}
	if (end == id)
	{
		args->end = 1;
		return (write_stuff(args, args->philo));
	}
	return (0);
}

int	is_dead(t_args *args)
{
	int		id;

	id = 0;
	while (id < args->phil_num)
	{
		args->time = set_time();
		if (args->philo[id].start + args->philo[id].last_meal
			< args->time)
		{
			args->dead_man = 1;
			usleep(10000);
			pthread_mutex_lock(&args->msg);
			printf("%ld ms %lld is dead\n", args->time, 
			args->philo[id].id);
			pthread_mutex_unlock(&args->msg);
			return (1);
		}
		id++;
	}
	return (0);
}
