#include "philo.h"

int		ft_atoi(const char *nptr)
{
	int		i;
	int		d;
	int		k;

	k = 0;
	i = 0;
	d = 1;
	while ((nptr[i] == ' ') || (nptr[i] == '\n') || (nptr[i] == '\f')
	|| (nptr[i] == '\v') || (nptr[i] == '\r') || (nptr[i] == '\t'))
		i++;
	if ((nptr[i] == '+') || (nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			d *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		k = k * 10 + (nptr[i] - '0');
		i++;
	}
	return (k * d);
}

int	ft_putendl(char *s)
{
	size_t	i;

	i = -1;
	if (s)
	{
		while (s[++i])
			write(1, &s[i], 1);
	}
	return (-1);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *d;

	d = s;
	while (n-- > 0)
		*d++ = c;
	return (s);
}

void	ft_putnbr_fd(int n, int fd)
{
	char r;

	if (n == -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2", 1);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		n = n * -1;
		write(fd, "-", 1);
		ft_putnbr_fd(n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else if (n < 10)
	{
		r = n + '0';
		write(fd, &r, 1);
	}
}
