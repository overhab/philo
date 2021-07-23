#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

# define EATING 1
# define THINKING 0
# define DEAD -1
# define SLEEP 2
# define L_FORK 3
# define R_FORK 4

typedef	pthread_mutex_t	t_mutex;

typedef	struct s_philo
{
	t_mutex		fork;
	int			id;
	long 	 	last_meal;
	int			eat_amount;
	int 		start;
	int			finish;
	int			status;
	pthread_t	thread;
}	t_philo;

typedef	struct s_args
{
	int 		phil_num; //number of philosophers/forks
	uint64_t	ttd; // time_to_die
	uint64_t	tte; //time_to_eat
	uint64_t	tts; //time_to_sleep
	int 		eat_amount; // (optional) how many times philosophers must eat
	t_mutex		monitor;
	t_mutex		*forks;
	t_mutex		msg;
	t_mutex		m_id;
	int			id;
	int			life;
	int			state;
	int			dead_man;
	int			end;
	long	 	time;
	long 		start;
	int			index;
	pthread_t	thread;
	t_philo		*philo;
}	t_args;

/* MAIN */
void			parse_args(t_args *args, char **av);
int				check_args(char **av);
int				_init_sim(t_args *args);
int				_start_sim(t_args *args);
int				_sleeping(t_args *args);

/* SIMULATION */
void			*simulation(void *arg);
void			sleep_think(t_args *args, int i);
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

/* UTILS */
int				ft_atoi(const char *nptr);
int				ft_putendl(char *s);
int				ft_isdigit(int c);
void			*ft_memset(void *s, int c, size_t n);
long			set_time(void);
void			ft_putnbr_fd(int n, int fd);

#endif