#include "sudoku.h"
#include "ft.h"

int		main(int argc, char **argv)
{
	int		*grille;
	int		*grilleCheck;
	
	globalSeparator = DEFAULT_SEPARATOR;
	if (argc < 2 || argc > 3)
		return (ft_putstr("Usage : sudoku <sudoku> [separator]\n"));
	if (argc == 3)
	{
		if (ft_strlen(argv[2]) == 1)
			globalSeparator = argv[2][0];
		else
			ft_putstr("Separator must be one character. Using default separator...\n");
	}
	grille = toGrille(argv[1]);
	grilleCheck = toGrille(argv[1]);
	if (grille == NULL)
		return (ft_putstr("Sudoku grid not recognize. It must contains 81 numbers and separator (default '.').\n"));
	showGrille(grille);
	if (resolve(grille, 0, 0) && resolve(grilleCheck, 0, 1) && compGrille(grille, grilleCheck))
	{
		clearGrille();
		showGrille(grille);
	}
	else
	{
		clearGrille();
		ft_putstr("Impossible!\n");
	}
	free(grille);
	free(grilleCheck);
	return (0);
}