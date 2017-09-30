#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	return (0);
}

int		ft_strlen(char *str)
{
	int r;
	
	r = 0;
	while (*str++)
		r++;
	return (r);
}

int		ft_strcmp(char *a, char *b)
{
	while (*a && *b && *a == *b)
	{
		a++;
		b++;
	}
	return (*a - *b);
}