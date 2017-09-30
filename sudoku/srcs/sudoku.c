#include "ft.h"
#include "sudoku.h"

int		resolve(int *grille, int pos, int reverse)
{
	int n;
	
	clearGrille();
	showGrille(grille);
	if (pos > 80)
		return (1);
	if (*(grille + pos) != 0)
	{
		if (column(grille, pos, *(grille + pos)) && line(grille, pos, *(grille + pos)) && block(grille, pos, *(grille + pos)))
			return (resolve(grille, pos + 1, reverse));
		else
			return (0);
	}
	n = (reverse ? 9 : 1);
	while ((!reverse && n < 10) || (reverse && n > 0))
	{
		if (column(grille, pos, n) && line(grille, pos, n) && block(grille, pos, n))
		{
			*(grille + pos) = n;
			if (resolve(grille, pos + 1, reverse))
				return (1);
			*(grille + pos) = 0;
		}
		if (reverse)
			n--;
		else
			n++;
	}
	return (0);
}

int		column(int *grille, int pos, int n)
{
	int x;
	int y;
	int curr;
	
	x = pos % 9;
	y = 0;
	while (y < 9)
	{
		curr = y * 9 + x;
		if (curr != pos && *(grille + curr) == n)
			return (0);
		y++;
	}
	return (1);
}

int		line(int *grille, int pos, int n)
{
	int x;
	int y;
	int curr;
	
	x = 0;
	y = pos / 9;
	while (x < 9)
	{
		curr = y * 9 + x;
		if (curr != pos && *(grille + curr) == n)
			return (0);
		x++;
	}
	return (1);
}

int		block(int *grille, int pos, int n)
{
	int bx;
	int by;
	int x;
	int y;
	int curr;
	
	bx = pos % 9 / 3;
	by = pos / 9 / 3;
	y = 0;
	while (y < 3)
	{
		x = 0;
		while (x < 3)
		{
			curr = (by * 3 + y) * 9 + (bx * 3 + x);
			if (curr != pos && *(grille + curr) == n)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int		*toGrille(char *input)
{
	int i;
	int *grille;
	
	i = 0;
	while (i < 81)
	{
		if (*(input + i) == '\0' || *(input + i) == '\n' || *(input + i) == '\t' || *(input + i) == ' ')
			return (NULL);
		i++;
	}
	if (*(input + i) != '\0')
		return (NULL);
	i = 0;
	if ((grille = (int*)malloc(sizeof(int) * 81)) == NULL)
		return (NULL);
	while (i < 81)
	{
		if (*(input + i) >= '0' && *(input + i) <= '9')
			*(grille + i) = *(input + i) - '0';
		else if (*(input + i) == globalSeparator)
			*(grille + i) = 0;
		else
			return (NULL);
		i++;
	}
	return (grille);
}

void	showGrille(int *grille)
{
	int i;
	
	i = 0;
	while (i < 81)
	{
		if (*(grille + i) == 0)
			ft_putchar(globalSeparator);
		else
			ft_putchar(*(grille + i) + '0');
		i++;
		if (i % 9 == 0)
			ft_putchar('\n');
		else if (i % 3 == 0)
			ft_putstr(" | ");
		else
			ft_putchar(' ');
		if (i == 27 || i == 54)
			ft_putstr("---------------------\n");
	}
}

int		compGrille(int *grilleA, int *grilleB)
{
	int i;
	
	i = 0;
	while (i < 81)
	{
		if (*(grilleA + i) != *(grilleB + i))
			return (0);
		i++;
	}
	return (1);
}

void	clearGrille()
{
	usleep(REFRESH_TIME);
	ft_putstr("\033[A\033[2K\033[A\033[2K\033[A\033[2K\033[A\033[2K\033[A\033[2K\033[A\033[2K\033[A\033[2K\033[A\033[2K\033[A\033[2K\033[A\033[2K\033[A\033[2K");
}