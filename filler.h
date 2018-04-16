#ifndef FILLER_H
# define FILLER_H

#include <stdlib.h>
#include <fcntl.h> // a ENLEVER
#include <unistd.h> // pareil

#include "./libft/includes/libft.h"

typedef struct s_piece t_piece;

typedef struct s_data t_data;

struct s_data
{
	char	symbol;
	int		rows;
	int		cols;
	int		**tab;
	char	**piece;
	int		piece_height;
	int		piece_width;
};

FILE *f; // a supprimer


int		tab_init(t_data *data);
void	tab_update(t_data *data);
int		tab_read(t_data *data, char c);
void	tab_free(t_data *data);

int piece_update(t_data *data);

#endif

// GESTION D'ERREURS C"EST COMMENT ?
// pas oublier de free les pieces juste apres les avoir placées
