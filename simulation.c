#include "philo.h"

void	*simulation(void *arg)
{
	t_args		*args;
	int			i;

	args = (t_args *)arg;
	i = args->id++;
	if (i % 2 == 0)
		usleep(args->tte);
	args->philo[i].start = set_time();
	//printf("%d is here\n", args->philo[i].id);
	while (1)
	{
		lunch(args, i);
		sleep_think(args, i);
		if (args->dead_man)
			return ((void*)0);
		if (check_eat_amount(args, i))
			break ;
	}
	args->philo[i].finish = 1;
	return ((void*)0);
}

int		_start_sim(t_args *args)
{
	args->start = set_time();
	args->index = 0;
	args->id = 0;
	while (args->index < args->phil_num)
	{
		if (pthread_create(&args->thread, NULL, &simulation, args) != 0)
			return (printf("???\n"));
		usleep(100);
		args->index++;
	}
	args->index = -1;
	while (++args->index < args->phil_num)
		pthread_join(args->thread, NULL);
	return (1);
}

int	check_eat_amount(t_args *args, int id)
{
	if (args->eat_amount < 0)
		return (0);
	else if (args->philo[id].finish == args->eat_amount)
		return (1);
	return (0);
}
