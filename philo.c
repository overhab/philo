#include "philo.h"

int	_freedom(t_args *args)
{
	args->index = 0;
	pthread_mutex_destroy(&args->msg);
	pthread_mutex_destroy(&args->monitor);
	while (args->index < args->phil_num)
		pthread_mutex_destroy(&args->forks[args->index++]);
	if (args->philo)
		free(args->philo);
	if (args->forks)
		free(args->forks);
	return (1);
}

int	join_loop(t_args *args, pthread_t *phil)
{
	args->index = -1;
	while (++args->index < args->phil_num)
		pthread_join(phil[args->index], NULL);
	free(phil);
	if (args->end)
	{
		pthread_mutex_lock(&args->msg);
		printf("%lld\tall done\n", set_time() - args->start);
		pthread_mutex_unlock(&args->msg);
	}
	return (1);
}	

int	_init_mutex(t_args *args)
{
	t_mutex		*init;

	args->index = 0;
	init = (t_mutex *)malloc(args->phil_num * sizeof(t_mutex));
	if (init == NULL)
		return (ft_putendl("Malloc Error\n"));
	while (args->index < args->phil_num)
		pthread_mutex_init(&init[args->index++], NULL);
	args->forks = init;
	return (1);
}

int	_init_philo(t_args *args)
{
	t_philo	*philo;

	args->index = 0;
	philo = (t_philo *)malloc(args->phil_num * sizeof(t_philo));
	if (philo == NULL)
		return (ft_putendl("Malloc Error\n"));
	while (args->index < args->phil_num)
	{
		ft_memset(&philo[args->index], 0, sizeof(t_philo));
		philo[args->index].id = args->index;
		philo[args->index].last_meal = set_time();
		args->index++;
	}
	args->philo = philo;
	return (0);
}
