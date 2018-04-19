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
	int		y_offset;
	int		x_offset;
	int		max_distance;
	int		candidate_y;
	int		candidate_x;
	int		candidate_dist;
};

FILE *f; // a supprimer
void print_tab(t_data *data); // pareil
void print_piece(t_data *data);

// GESTION D'ERREURS C"EST COMMENT ?
void	reader_skip_line(void);
int		reader_tab_dimensions(t_data *data);
int		reader_piece_dimensions(t_data *data);
void	reader_free_info(char *input, char **info, int read);


int		tab_init(t_data *data);
int		tab_update(t_data *data);
int		tab_read(t_data *data, char c);
void	tab_free(t_data *data);

int		piece_update(t_data *data);
void	piece_revise_height(t_data *data);
void	piece_revise_width(t_data *data);
void	piece_free(t_data *data);

void	trim_height_top(t_data *data);
void	trim_height_bottom(t_data *data);
void	trim_width_left(t_data *data);
void	trim_width_right(t_data *data);
void	trim_piece(t_data *data);


int		cell_authorized(t_data *data, int y, int x);
void	cell_eval_distance(t_data *data, int y, int x, int size);
void	cell_fill(t_data *data, int y, int x);

int player_play(t_data *data);
void player_eval_map(t_data *data);

#endif
