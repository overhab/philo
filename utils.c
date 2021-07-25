#include "philo.h"

int	ft_atoi(const char *nptr)
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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*d;

	d = s;
	while (n-- > 0)
		*d++ = c;
	return (s);
}
