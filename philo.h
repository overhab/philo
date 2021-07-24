#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define EATING 1
# define THINKING 0
# define DEAD -1
# define SLEEP 2
# define L_FORK 3
# define R_FORK 4

typedef	pthread_mutex_t	t_mutex;

typedef	struct s_philo
{
	t_mutex		eating;
	int			id;
	long long 	last_meal;
	int			eat_amount;
	long long	start;
	int			finish;
	int			status;
	pthread_t	thread;
}	t_philo;

typedef	struct s_args
{
	int		 		phil_num;
	unsigned int	ttd;
	unsigned int	tte;
	unsigned int	tts;
	int				eat_amount;
	t_mutex			monitor;
	int				monitoring;
	t_mutex			*forks;
	t_mutex			msg;
	t_mutex			m_id;
	int				id;
	int				state;
	int				dead_man;
	int				end;
	long long		time;
	long long 		start;
	int				index;
	pthread_t		thread;
	t_philo			*philo;
}	t_args;

/* MAIN */
void			parse_args(t_args *args, char **av);
int				check_args(char **av);
int				valid_args(t_args args, int ac);
int				_init_sim(t_args *args);
int				_start_sim(t_args *args);
int				_sleeping(t_args *args);

/* SIMULATION */
void			*simulation(void *arg);
void			sleep_think(t_args *args, int i);
void			thinking(t_args *args, int i);
void			lunch(t_args *args, int id);
int				check_eat_amount(t_args *args, int id);

/* MONITORING */
void			*monitoring(void *arg);
int				all_done(t_args *args);
int				is_dead(t_args *args);

/* PRINT_STATUS */
int				write_stuff(t_args *args, int i);
char			*compose_message(t_args *args, int id);

/* PHILO */
int				_init_philo(t_args *args);
int				_init_mutex(t_args *args);
void			unlock_and_destroy(t_mutex mutex);
int				_freedom(t_args *args);
int				join_loop(t_args *args, pthread_t *phil);

/* UTILS */
int				ft_atoi(const char *nptr);
int				ft_putendl(char *s);
int				ft_isdigit(int c);
void			*ft_memset(void *s, int c, size_t n);
long long		set_time(void);
void			my_usleep(long sec);

#endif