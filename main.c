#include "philo.h"

int	_init_sim(t_args *args)
{
	if (_init_mutex(args) == -1)
		return (_freedom(args));
	if (_init_philo(args) == -1)
		return (_freedom(args));
	pthread_mutex_init(&args->msg, NULL);
	pthread_mutex_init(&args->monitor, NULL);
	_start_sim(args);
	usleep(10000);
	return (_freedom(args));
}

long long	set_time(void)
{
	struct timeval	time;
	long long		ms;

	gettimeofday(&time, NULL);
	ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ms);
}

int	check_args(char **av)
{
	int	i;
	int	d;

	i = 1;
	while (av[i])
	{
		d = 0;
		while (av[i][d])
		{
			if (!ft_isdigit(av[i][d]))
				return (0);
			d++;
		}
		i++;
	}
	return (1);
}

int	valid_args(t_args args, int ac)
{
	if (ac == 6)
	{
		if (args.phil_num < 1 || args.ttd < 1 || args.tte < 1
			|| args.tts < 1 || args.eat_amount <= 0)
			return (0);
	}
	if (ac == 5)
	{
		if (args.phil_num < 1 || args.ttd < 1 || args.tte < 1
			|| args.tts < 1)
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_args	args;

	if (ac == 5 || ac == 6)
	{
		if (check_args(av))
		{
			ft_memset(&args, 0, sizeof(t_args));
			args.phil_num = ft_atoi(av[1]);
			args.ttd = ft_atoi(av[2]) * 1000;
			args.tte = ft_atoi(av[3]) * 1000;
			args.tts = ft_atoi(av[4]) * 1000;
			args.eat_amount = -1;
			if (ac == 6)
				args.eat_amount = ft_atoi(av[5]);
			args.start = set_time();
			if (valid_args(args, ac))
				return (_init_sim(&args));
		}
	}
	ft_putendl("Wrong arguments\n");
	return (0);
}
