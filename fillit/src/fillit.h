#ifndef FILLIT_FILLIT_H
#define FILLIT_FILLIT_H
/*
**Tetrimino is a classic piece of Tetris composed of 4 blocks.
**This structure stores the coordinates of figure + character which designate
**order of figures
*/

#include "../includes/libft/libft.h"

#define BUFSIZ 21
typedef struct	s_piece
{
	char		letter;
	short		coord[4][2];
}				t_piece;

t_list		*ft_figure_extract(int string);
t_piece		*detect_figure(char *buf, int length, char letter);
t_piece		*get_coordinates(t_piece *temp, char buf[]);
void solve(t_list *pList_fig);
int			solve_tetrimino(char **array, int size, t_list *pList);
char		**get_array(int size);
int			place(char **pArray, short y, short x, int size,
		short *pCoord ,char letter);
void		place_out(char **pArray, short y, short x, short *pCoord);
int			high_sqrt(int n);
#endif
/*
**End of define #FILLIT_FILLIT_H
*/