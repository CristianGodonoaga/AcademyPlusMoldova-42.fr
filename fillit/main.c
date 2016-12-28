#include "../libft/libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

void print_arr(char **array , int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (array[i][j])
				printf("%c", array[i][j]);
			else
			printf(".");
		}
		printf("\n");
	}
	printf("\n");
}

int			main(int argc, char **argv)
{
	int		fd;
	t_list	*tList_figures;
	char 	**array;

    if(argc != 2)
    {
        ft_putstr("number of parameter is invalid");
        return (0);
    }
    if(!(tList_figures = ft_figure_extract(fd =
			open(argv[1], O_RDONLY | O_CREAT))))
    {
        ft_putstr("error\n");
        return (0);
    }
	close(fd);
	array = solve(tList_figures);

	return (0);
}


int			high_sqrt(int n)
{
	int		size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

char		**solve(t_list *pList_fig)
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

int			solve_tetrimino(char **array, int size, t_list *pList)
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

void place_out(char **pArray, short y, short x, short *pCoord)
{
	pArray[y + pCoord[0]][x + pCoord[1]] = 0;
	pArray[y + pCoord[2]][x + pCoord[3]] = 0;
	pArray[y + pCoord[4]][x + pCoord[5]] = 0;
	pArray[y + pCoord[6]][x + pCoord[7]] = 0;
}

int place(char **pArray, short y, short x, int size, short *pCoord, char letter)
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

char **get_array(int size)
{
	char 	**temp;
	int 	i;
	int 	j;

	temp = (char**)malloc(sizeof(char*) * size);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < size)
	{
		j = 0;
		*(temp + i) = (char *)malloc(sizeof(char) * size);
		if (!(temp + i))
			return (NULL);
		while (j < size)
		{
			*(*(temp + i) + j) = 0;
			j++;
		}
		i++;
	}
	return (temp);
}
/*
**
**
**
*/
t_list      *ft_figure_extract(int fd)
{
    char    buf[BUFSIZ + 1];
    int		length;
    char    letter;
    t_list  *list_head;
    t_piece *temp;
	char    mark;

    letter = 'A';
	mark = 0;
	list_head = NULL;
    while (((length = (int)read(fd, buf, 21)) >= 20) &&
		    (temp = detect_figure(buf, length, letter++)))
    {
        mark = (length == 21);
        ft_lstadd(&list_head, ft_lstnew(temp, sizeof(*temp)));
        free(temp);
    }
	if (mark || length)
	{
		ft_lstfree(&list_head);
		return (NULL);
	}
	return (list_head);
}

/*
**
*/
t_piece			*detect_figure(char *buf, int length, char letter)
{
    t_piece		*temp;

    if (length == 21 && buf[20] != '\n')
        return (NULL);
    temp = (t_piece*)malloc(sizeof(*temp));
	if (!temp)
        return (NULL);
	if (!(temp = get_coordinates(temp, buf)))
	{
		free(temp);
		return (NULL);
	}
	temp->letter = letter;
	temp->coord[1][0] -= temp->coord[0][0];
	temp->coord[1][1] -= temp->coord[0][1];
	temp->coord[2][0] -= temp->coord[0][0];
	temp->coord[2][1] -= temp->coord[0][1];
	temp->coord[3][0] -= temp->coord[0][0];
	temp->coord[3][1] -= temp->coord[0][1];
	temp->coord[0][0] = 0;
	temp->coord[0][1] = 0;
    return (temp);
}
/*
**Check and validate the tetriminos figure
*/
t_piece*     get_coordinates(t_piece *temp, char buf[])
{
    short   i;
    short   j;

    i = 0;
    j = 0;
    while ((buf[i] == '#' || buf[i] == '.' || buf[i] == 1) ||
            (!(i % 5 < 4) && buf[i] == '\n') && i < 20)
    {
        if ((buf[i] == '#' && !j || (buf[i] == '#' && buf[i +1 ] == 1)) ||
				buf[i] == 1)
        {
			if (j > 3)
				return (NULL);
            temp->coord[j][0] = (short)((i + 1) / 5);
            temp->coord[j][1] = (short)(i - ((i + 1) / 5) * 5);
            if (((i + 1) % 5) && buf[i + 1] == '#')
                buf[i + 1] = 1;
            if ((i + 5 < 20) && buf[i + 5] == '#')
                buf[i + 5] = 1;
            j++;
        }
        i++;
    }
    if (j == 4)
        return (temp);
    return (NULL);
}