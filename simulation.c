#include "philo.h"

void	*simulation(void *arg)
{
	t_args		*args;
	int			i;

	args = (t_args *)arg;
	i = args->id++;
	if (i % 2 != 0)
		usleep(args->tte);
	args->philo[i].finish = 0;
	args->philo[i].start = set_time();
	while (1)
	{
		lunch(args, i);
		if (check_eat_amount(args, i) && (args->eat_amount > 0))
			break ;
		sleep_think(args, i);
		if (args->dead_man)
			return (0);
	}
	args->philo[i].finish = 1;
	return (0);
}

int	_start_sim(t_args *args)
{
	pthread_t	*phil;

	phil = malloc(sizeof(pthread_t) * args->phil_num);
	if (phil == NULL)
		return (ft_putendl("Malloc Error\n"));
	args->start = set_time();
	args->index = 0;
	args->id = 0;
	while (args->index < args->phil_num)
	{
		if (pthread_create(&phil[args->index], NULL, &simulation, args) != 0)
			return (ft_putendl("Pthread Error\n"));
		args->index++;
	}
	args->monitoring = 1;
	args->index = -1;
	if (monitoring(args) == 0)
		return (join_loop(args, phil));
	return (1);
}

int	check_eat_amount(t_args *args, int id)
{
	if (args->eat_amount < 0)
		return (0);
	if (args->philo[id].finish == args->eat_amount)
		return (1);
	return (0);
}
