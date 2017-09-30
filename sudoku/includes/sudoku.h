#ifndef SUDOKU_H
# define SUDOKU_H

# include <stdlib.h>
# include <unistd.h>
# include "ft.h"

# define DEFAULT_SEPARATOR '.'
# define REFRESH_TIME 30000 // 1s = 100000

int		resolve(int *grille, int pos, int reverse);
int		column(int *grille, int pos, int n);
int		line(int *grille, int pos, int n);
int		block(int *grille, int pos, int n);
int		*toGrille(char *input);
void	showGrille(int *grille);
int		compGrille(int *grilleA, int *grilleB);
void	clearGrille();

char	globalSeparator;

#endif