//#include "../libft/libft.h"
//#include "fillit.h"
//#include <fcntl.h>
//#include <stdio.h>
//#include <errno.h>
//#include <string.h>
//#include <stdbool.h>
//
//
//t_list		*ft_figure_extract(int string);
//
//t_piece		*detect_figure(char *buf, int length, char letter);
//
//t_piece		*get_coordinates(t_piece *temp, char buf[]);
//
//char		**solve(t_list *pList_fig);
//
//int			solve_tetrimino(char **array, int size, t_list *pList);
//
//char **get_array(int size);
//
//int place(char **arr, short x, short y, int size, t_list *pList);
//
//void place_out(char **pArray, short x, short y, short *pCoord);
//
//void        ft_lstfree(t_list **pT_head)
//{
//	t_list	*ptr_next;
//
//	while (*pT_head)
//	{
//		ptr_next = (*pT_head)->next;
//		free((*pT_head)->content);
//		free(*pT_head);
//		*pT_head = ptr_next;
//	}
//	*pT_head = NULL;
//}
//void print_arr(char **array , int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		for (int j = 0; j < size; ++j) {
//			printf("%c", array[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
//
//int			main(int argc, char **argv)
//{
//    int		fd;
//    t_list	*tList_figures;
//	char 	**array;
//
//    if(argc != 2)
//    {
//        ft_putstr("number of parameter is invalid");
//        return (0);
//    }
//    if(!(tList_figures = ft_figure_extract(fd = open(argv[1], O_RDONLY | O_CREAT))))
//    {
//        ft_putstr("error");
//        return (0);
//    }
//	close(fd);
//	array = solve(tList_figures);
//
//	//print
//    return (0);
//}
//
//
//int			high_sqrt(int n)
//{
//	int size;
//
//	size = 2;
//	while (size * size < n)
//		size++;
//	return (size);
//}
//
//char		**solve(t_list *pList_fig)
//{
//	int 	size;
//	char 	**array;
//	size = high_sqrt((((t_piece*)(pList_fig->content))->letter - '@') * 4);
//	if (size < 4)
//		size = 4;
//	array = get_array(size + 1);
//	if (solve_tetrimino(array, size, pList_fig))
//	{
//		print_arr(array, size);
//		return (array);
//	}
//	if (solve_tetrimino(array, size + 1, pList_fig))
//	{
//		print_arr(array, size +1);
//		return (array);
//	}
//	return NULL;
//}
//
//int			solve_tetrimino(char **array, int size, t_list *pList)
//{
//	short	x;
//	short 	y;
//	short	*coord;
//
//	if (!pList)
//		return (1);
//	y = 0;
//	while (y < size)
//	{
//		x = 0;
//		while (x < size)
//		{
//			if (place(array, x, y, size, pList))
//				if (solve_tetrimino(array, size, pList->next))
//					return (1);
//				else
//					place_out(array, x, y, &((t_piece*)(pList->content))
//							->coord[0][0]);
//			x++;
//		}
//		y++;
//	}
//	return (0);
//}
//
//void place_out(char **pArray, short x, short y, short *pCoord)
//{
//	pArray[x + pCoord[0]][y + pCoord[1]] = 1;
//	pArray[x + pCoord[2]][y + pCoord[3]] = 1;
//	pArray[x + pCoord[4]][y + pCoord[5]] = 1;
//	pArray[x + pCoord[6]][y + pCoord[7]] = 1;
//}
//
//int			place(char **arr, short x, short y, int size, t_list *pList)
//{
//	short	i;
//	short	*Coord;
//
//	Coord = &((t_piece*)(pList->content))->coord[0][0];
//	i = 0;
//	while (i < 7 && x + Coord[i] < size && y + Coord[i + 1] < size &&
//			x + Coord[i] >= 0 && y + Coord[i + 1] >= 0)
//		i += 2;
//	if (i == 8 &&  arr[x + Coord[0]][y + Coord[1]] && arr[x +
//			Coord[2]][y + Coord[3]] && arr[x + Coord[4]][y +
//			Coord[5]] && arr[x + Coord[6]][y + Coord[7]])
//	{
//		char c = ((t_piece*)(pList->content))->letter;
//		arr[x + Coord[0]][y + Coord[1]] = ((t_piece*)(pList->content))->letter;
//		arr[x + Coord[2]][y + Coord[3]] = ((t_piece*)(pList->content))->letter;
//		arr[x + Coord[4]][y + Coord[5]] = ((t_piece*)(pList->content))->letter;
//		arr[x + Coord[6]][y + Coord[7]] = ((t_piece*)(pList->content))->letter;
//		print_arr(arr, size);
//		return (1);
//	}
//	return (0);
//}
//
//char **get_array(int size)
//{
//	char 	**temp;
//	int 	i;
//	int 	j;
//
//	temp = (char**)malloc(sizeof(char*) * size);
//	if (!temp)
//		return (NULL);
//	i = 0;
//	while (i < size)
//	{
//		j = 0;
//		*(temp + i) = (char *)malloc(sizeof(char) * size);
//		if (!(temp + i))
//			return (NULL);
//		while (j < size)
//		{
//			*(*(temp + i) + j) = 1;
//			j++;
//		}
//		i++;
//	}
//	return (temp);
//}
///*
//**
//**
//**
//*/
//t_list      *ft_figure_extract(int fd)
//{
//	char    buf[BUFSIZ + 1];
//	int		length;
//	char    letter;
//	t_list  *list_head;
//	t_piece *temp;
//	char    mark;
//
//	letter = 'A';
//	mark = 0;
//	list_head = NULL;
//	while (((length = (int)read(fd, buf, 21)) >= 20) &&
//			(temp = detect_figure(buf, length, letter++)))
//	{
//		mark = (length == 21);
//		ft_lstadd(&list_head, ft_lstnew(temp, sizeof(*temp)));
//		free(temp);
//	}
//	if (mark || length)
//	{
//		ft_lstfree(&list_head);
//		return (NULL);
//	}
//	ft_lstrevers(&list_head);
//	return (list_head);
//}
//
///*
//**
//*/
//t_piece			*detect_figure(char *buf, int length, char letter)
//{
//	t_piece		*temp;
//
//	if (length == 21 && buf[20] != '\n')
//		return (NULL);
//	temp = (t_piece*)malloc(sizeof(*temp));
//	if (!temp || !(temp = get_coordinates(temp, buf)))
//		return (NULL);
//	temp->letter = letter;
//	temp->coord[1][0] -= temp->coord[0][0];
//	temp->coord[1][1] -= temp->coord[0][1];
//	temp->coord[2][0] -= temp->coord[0][0];
//	temp->coord[2][1] -= temp->coord[0][1];
//	temp->coord[3][0] -= temp->coord[0][0];
//	temp->coord[3][1] -= temp->coord[0][1];
//	temp->coord[0][0] = 0;
//	temp->coord[0][1] = 0;
//	return (temp);
//}
///*
//**Check and validate the tetriminos figure
//*/
//t_piece*     get_coordinates(t_piece *temp, char buf[])
//{
//	short   i;
//	short   j;
//
//	i = 0;
//	j = 0;
//	while ((buf[i] == '#' || buf[i] == '.' || buf[i] == 1) ||
//			(!(i % 5 < 4) && buf[i] == '\n') && i < 20)
//	{
//		if ((buf[i] == '#' && !j) || buf[i] == 1)
//		{
//			temp->coord[j][0] = (short)((i + 1) / 5);
//			temp->coord[j][1] = (short)(i - ((i + 1) / 5) * 5);
//			if (((i + 1) % 5) && buf[i + 1] == '#')
//				buf[i + 1] = 1;
//			if ((i + 5 < 20) && buf[i + 5] == '#')
//				buf[i + 5] = 1;
//			j++;
//		}
//		i++;
//	}
//	if(j == 4)
//		return (temp);
//	return (NULL);
//}