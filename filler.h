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
	int		max_distance;
	int		adv_y;
	int		adv_x;
};

FILE *f; // a supprimer

void	reader_skip_line(void);
int		reader_tab_dimensions(t_data *data);
int		reader_piece_dimensions(t_data *data);
void	reader_free_info(char *input, char **info, int read);


int		tab_init(t_data *data);
int		tab_update(t_data *data);
int		tab_read(t_data *data, char c);
void	tab_free(t_data *data);

int		piece_update(t_data *data);
void	piece_put(t_data *data, int y, int x);
int		piece_has_room(t_data *data, int y, int x);
void	piece_free(t_data *data);


int player_play(t_data *data);
// int player_try(t_data *data, int i, int j);


#endif

// GESTION D'ERREURS C"EST COMMENT ?
// pas oublier de free les pieces juste apres les avoir placées
