#include "fillit.h"

void	print_arr(char **array , int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (array[i][j])
				ft_putchar(array[i][j]);
			else
				ft_putchar('.');
		}
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

char	**solve(t_list *pList_fig)
{
	int 	size;
	char 	**array;
	size = high_sqrt((((t_piece*)(pList_fig->content))->letter - '@') * 4);
	if (size < 4)
		size = 4;
	ft_lstrevers(&pList_fig);
	array = get_array(size + 1);
	if (solve_tetrimino(array, size, pList_fig))
		print_arr(array, size);
	if (solve_tetrimino(array, size + 1, pList_fig))
		print_arr(array, size +1);
	//free()
	return NULL;
}

int		solve_tetrimino(char **array, int size, t_list *pList)
{
	short	x;
	short 	y;
	short	*coord;
	char	letter;

	if (!pList)
		return (1);
	coord = &((t_piece*)(pList->content))->coord[0][0];
	letter = ((t_piece*)(pList->content))->letter;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (place(array, y, x, size, coord, letter))
				if (solve_tetrimino(array, size, pList->next))
					return (1);
				else
					place_out(array, y, x, coord);
			x++;
		}
		y++;
	}
	return (0);
}

void	place_out(char **pArray, short y, short x, short *pCoord)
{
	pArray[y + pCoord[0]][x + pCoord[1]] = 0;
	pArray[y + pCoord[2]][x + pCoord[3]] = 0;
	pArray[y + pCoord[4]][x + pCoord[5]] = 0;
	pArray[y + pCoord[6]][x + pCoord[7]] = 0;
}

int		place(char **pArray, short y, short x, int size, short *pCoord, char letter)
{
	short	i;

	i = 0;
	while (i < 7 && y + pCoord[i] < size && x + pCoord[i + 1] < size &&
			y + pCoord[i] >= 0 && x + pCoord[i + 1] >= 0)
		i += 2;
	if (i == 8 && !(pArray[y + pCoord[0]][x + pCoord[1]] || pArray[y +
			pCoord[2]][x + pCoord[3]] || pArray[y + pCoord[4]][x +
			pCoord[5]] || pArray[y + pCoord[6]][x + pCoord[7]]))
	{
		pArray[y + pCoord[0]][x + pCoord[1]] = letter;
		pArray[y + pCoord[2]][x + pCoord[3]] = letter;
		pArray[y + pCoord[4]][x + pCoord[5]] = letter;
		pArray[y + pCoord[6]][x + pCoord[7]] = letter;
		//printf("x = %i, y = %i\n", x, y);
		//print_arr(pArray, size);
		return (1);
	}
	return (0);
}
